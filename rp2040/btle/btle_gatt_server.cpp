#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "btstack.h"

// GATT handles
static btstack_packet_callback_registration_t hci_event_callback;
static uint16_t gatt_client_conn_handle = 0;
static uint16_t notify_char_handle = 0;
static uint16_t write_char_handle = 0;
static uint32_t random_pin = 0;

// Generate random 6-digit PIN
uint32_t generate_random_pin() {
    return (rand() % 900000) + 100000;
}

// Send 5-char string
static void send_string(const char *str) {
    if (write_char_handle == 0) {
        printf("No write characteristic found\n");
        return;
    }
    uint8_t data[5];
    memcpy(data, str, 5);
    gatt_client_write_value_of_characteristic(gatt_client_conn_handle,
        write_char_handle | 0x01, 5, data);
    printf("Sent 5-char: %.5s\n", str);
}

// GATT event handler
static void gatt_event_handler(uint8_t packet_type, uint16_t channel,
                              uint8_t *packet, uint16_t size) {
    if (packet_type != HCI_EVENT_PACKET) return;

    uint8_t event = hci_event_packet_get_type(packet);

    switch (event) {
        case GATT_EVENT_CHARACTERISTIC_QUERY_RESULT:
            {
                uint16_t uuid16 = gatt_event_characteristic_query_result_get_uuid16(packet);
                uint16_t properties = gatt_event_characteristic_query_result_get_properties(packet);

                // Look for notify (0x10) and write (0x08) characteristics
                if (properties & 0x10 && notify_char_handle == 0) { // Notify
                    notify_char_handle = gatt_event_characteristic_query_result_get_handle(packet);
                    printf("Notify char found: 0x%04x\n", notify_char_handle);
                }
                if (properties & 0x08 && write_char_handle == 0) { // Write w/o resp
                    write_char_handle = gatt_event_characteristic_query_result_get_handle(packet);
                    printf("Write char found: 0x%04x\n", write_char_handle);
                }
            }
            break;

        case GATT_EVENT_QUERY_COMPLETE:
            printf("GATT discovery complete\n");
            if (notify_char_handle) {
                gatt_client_listen(gatt_client_conn_handle, notify_char_handle | 0x01, 1);
            }
            if (write_char_handle) {
                send_string("HELLO");  // Send 5-char string
            }
            break;

        case GATT_EVENT_NOTIFICATION:
            {
                uint16_t value_handle = little_endian_read_16(packet, 4);
                uint16_t value_len = little_endian_read_16(packet, 6);
                printf("Received 5-char: %.5s\n", &packet[8]);
            }
            break;
    }
}

// Main packet handler
static void packet_handler(uint8_t packet_type, uint16_t channel,
                          uint8_t *packet, uint16_t size) {
    if (packet_type != HCI_EVENT_PACKET) return;

    uint8_t event = hci_event_packet_get_type(packet);

    switch (event) {
        case BTSTACK_EVENT_STATE:
            if (btstack_event_state_get_state(packet) == BTSTACK_STATE_WORKING) {
                printf("BTstack ready - scanning...\n");
                gap_set_scan_parameters(1, 0x0030, 0x0030);
                gap_start_scan();
            }
            break;

        case GAP_EVENT_ADVERTISING_REPORT:
            {
                bd_addr_t addr;
                gap_event_advertising_report_get_address(packet, addr);
                printf("Device found: %s\n", bd_addr_to_str(addr));
                gap_stop_scan();
                gap_connect(addr, bd_addr_type_le_public);
            }
            break;

        case GAP_EVENT_CONNECTION_COMPLETE:
            gatt_client_conn_handle = gap_event_connection_complete_get_connection_handle(packet);
            printf("Connected (handle %d), starting pairing...\n", gatt_client_conn_handle);
            sm_request_pairing(gatt_client_conn_handle);
            break;

        case SM_EVENT_JUST_WORKS_REQUEST:
        case SM_EVENT_PASSKEY_DISPLAY_NUMBER:
            random_pin = generate_random_pin();
            printf("Secure PIN: %06u (enter on peripheral)\n", random_pin);
            sm_passkey_input(gatt_client_conn_handle, random_pin);
            break;

        case GAP_EVENT_DISCONNECTION_COMPLETE:
            printf("Disconnected - restarting scan\n");
            gap_start_scan();
            notify_char_handle = write_char_handle = 0;
            break;

        case GATT_EVENT_SERVICE_QUERY_RESULT:
            // Start characteristic discovery
            gatt_client_discover_characteristics_for_service(gatt_client_conn_handle,
                gatt_event_service_query_result_get_attribute_handle(packet));
            break;

        case GATT_EVENT_QUERY_COMPLETE:
            if (little_endian_read_16(packet, 4) == 0) {
                gatt_client_discover_primary_services_by_uuid128(gatt_client_conn_handle,
                    (uint8_t*)"0000180a-0000-1000-8000-00805f9b34fb");  // Device Info service example
            }
            break;
    }
}

int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("CYW43 init failed\n");
        return 1;
    }

    srand(12345);  // Seed random

    // BTStack init
    btstack_memory_init();
    btstack_run_loop_init(btstack_run_loop_get_instance());

    hci_init(hci_transport_usb(), NULL);
    hci_set_chipset(&cyw43_btstack_chipset);

    l2cap_init();
    l2cap_register_packet_handler(packet_handler);

    sm_init();
    sm_set_io_capabilities(IO_CAPABILITY_KEYBOARD_ONLY);
    sm_set_authentication_requirements(SM_AUTHREQ_BONDING | SM_AUTHREQ_MITM_PROTECTION);

    // GATT client
    gatt_client_register_packet_handler(gatt_event_handler);

    printf("RP240W BLE Host starting...\n");
    btstack_run_loop_execute();

    cyw43_arch_deinit();
    return 0;
}

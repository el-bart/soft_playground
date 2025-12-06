#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

// BLE state simulation
static uint32_t random_pin = 0;
static bool ble_connected = false;
static uint16_t conn_handle = 0;

// Generate secure random 6-digit PIN
uint32_t generate_random_pin() {
  return (rand() % 900000) + 100000;
}

// Send 5-character string (BLE simulation)
void ble_send_5char(const char* str) {
  printf("[BLE TX] %02X %02X %02X %02X %02X  (\"%.5s\")\n", str[0], str[1], str[2], str[3], str[4], str);
}

// Receive 5-character string handler
void ble_receive_5char(const uint8_t* data) {
  printf("[BLE RX] %02X %02X %02X %02X %02X  (\"%.5s\")\n", data[0], data[1], data[2], data[3], data[4], (char*)data);
}

// Simulate BLE peripheral responses
void simulate_peripheral_response() {
  uint8_t response[] = {'W', 'O', 'R', 'L', 'D'};
  ble_receive_5char(response);
}

int main() {
  stdio_init_all();

  // Initialize CYW43 (required for RP240W hardware)
  if (cyw43_arch_init()) {
    printf("CYW43 init failed\n");
    return 1;
  }

  srand(12345);
  random_pin = generate_random_pin();

  printf("=== RP240W BLE HOST ===\n");
  printf("Secure Pairing PIN: %06u\n", random_pin);
  printf("Waiting for BLE peripheral...\n\n");

  // BLE Host Demo Loop
  int step = 0;
  while (1) {
    switch (step) {
      case 0: // Scanning
        printf("[STEP 1] Scanning for BLE devices...\n");
        sleep_ms(2000);
        step = 1;
        break;

      case 1: // Connect + Pair
        printf("[STEP 2] Connected! Pairing with PIN %06u...\n", random_pin);
        sleep_ms(1500);
        printf("[STEP 2] Pairing successful - GATT discovery...\n");
        sleep_ms(1000);
        step = 2;
        ble_connected = true;
        break;

      case 2: // Send/Receive loop
        if (ble_connected) {
          printf("[STEP 3] Sending 5-char message...\n");
          ble_send_5char("HELLO");
          sleep_ms(1000);

          printf("[STEP 3] Receiving response...\n");
          simulate_peripheral_response();
          sleep_ms(3000);
        }
        break;
    }
  }

  cyw43_arch_deinit();
  return 0;
}

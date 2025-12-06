#pragma once
#include "lwipopts_examples_common.h"

// CYW43 specific settings
#define CYW43_LWIP 1
#define NO_SYS 1
#define LWIP_SINGLE_THREADED 1

#define LWIP_DHCP 0  // Disable DHCP for BLE-only
#define LWIP_IPV4 0
#define LWIP_IPV6 0

#define MEM_ALIGNMENT 4
#define MEM_SIZE 16000
#define MEMP_NUM_PBUF 16
#define MEMP_NUM_UDP_PCB 4
#define MEMP_NUM_TCP_PCB 8
#define MEMP_NUM_TCP_PCB_LISTEN 8
#define MEMP_NUM_TCP_SEG 32
#define MEMP_NUM_SYS_TIMEOUT 3

#define LWIP_ARP 1
#define LWIP_ETHERNET 1
#define LWIP_ICMP 1
#define LWIP_RAW 1

#define TCPIP_THREAD_NAME "TCP/IP"
#define TCPIP_THREAD_STACKSIZE 4096
#define TCPIP_MBOX_SIZE 8
#define LWIP_TCPIP_CORE_LOCKING 1

#define ETH_PAD_SIZE 0
#define PBUF_LINK_HLEN 16

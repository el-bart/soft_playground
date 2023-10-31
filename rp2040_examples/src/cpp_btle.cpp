#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <iostream>

int main()
{
  // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  uart_init(uart0, 115200);

  unsigned n = 0;
  while(true)
  {
    std::cout << "#" << n << ": hello, world!\n\r";
    sleep_ms(500);
    ++n;
  }
}

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <sstream>

int main() {
  // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  uart_init(uart0, 115200);

  unsigned n = 0;
  while(true)
  {
    std::stringstream ss;
    ss << "#" << n << ": hello, world!\n\r";
    uart_puts(uart0, ss.str().c_str());
    sleep_ms(500);
    ++n;
  }
}


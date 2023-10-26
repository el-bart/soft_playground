#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "nlohmann/json.hpp"
#include <iostream>

int main()
{
  // Set the GPIO pin mux to the UART - 0 is TX, 1 is RX
  gpio_set_function(0, GPIO_FUNC_UART);
  gpio_set_function(1, GPIO_FUNC_UART);
  uart_init(uart0, 115200);

  stdio_uart_init();

  unsigned n = 0;
  while(true)
  {
    try
    {
      std::cout << "#" << n << ": json, plz!\n\r";
      nlohmann::json j;
      std::cin >> j;
      std::cout << "\n\r" << "here's the pretty version!\n\r";
      std::cout << std::setw(2) << j << "\n\r";
      ++n;
    }
    catch(std::exception const &ex)
    {
      std::cerr << "ERROR: " << ex.what() << "\n\r";
    }
  }
}


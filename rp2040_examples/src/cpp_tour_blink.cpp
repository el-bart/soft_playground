#include "pico/stdlib.h"
#include <vector>
#include <stdexcept>
#include <atomic>

int main()
{
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  std::vector<char> v;
  v.resize(240*1024);    // 256k is available in total. v.size()==250k is already a crash
  std::atomic<bool> quit{true};

  do
  {
    constexpr auto delay = 100;
    try
    {
      quit = false;
      gpio_put(LED_PIN, 1);
      sleep_ms(delay);
      throw std::runtime_error{"whazzup!"};
    }
    catch(...)
    {
      gpio_put(LED_PIN, 0);
      sleep_ms(delay);
    }
  }
  while (not quit);
}

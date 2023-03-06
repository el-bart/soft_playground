#include "pico/stdlib.h"

int main()
{
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  do
  {
    constexpr auto delay = 100;
    gpio_put(LED_PIN, 1);
    sleep_ms(delay);
    gpio_put(LED_PIN, 0);
    sleep_ms(delay);
  }
  while (true);
}

#include <limits>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main()
{
  // slice for GPIO 2 and 3:
  auto const slice_num = pwm_gpio_to_slice_num(2);

  pwm_config cfg = pwm_get_default_config();
#if 0
  pwm_config_set_clkdiv(&cfg, 38);  // 125*10^6 / 2^16 / 38 ~= 50Hz
#else
  pwm_config_set_clkdiv_int_frac(&cfg, 38, 2); // div == 38 + 2/16
#endif
  {
    auto const invert = false;
    pwm_config_set_output_polarity(&cfg, invert, invert); // invert both channels
  }
  pwm_init(slice_num, &cfg, false);

  // GPIO 2 & 3 -> PWM
  gpio_set_function(2, GPIO_FUNC_PWM);
  gpio_set_function(3, GPIO_FUNC_PWM);

  auto const max = std::numeric_limits<uint16_t>::max();
  uint16_t top1 = max / 20u;
  uint16_t top2 = max / 20u + 100u;

  pwm_set_wrap(slice_num, max);                     // period
  pwm_set_chan_level(slice_num, PWM_CHAN_A, top1);
  pwm_set_chan_level(slice_num, PWM_CHAN_B, top2);

  pwm_set_enabled(slice_num, true);

  // make PWM nicely float, at different speeds
  while(true)
  {
    sleep_ms(1);
    top1 += 2;
    top2 += 8;
    pwm_set_chan_level(slice_num, PWM_CHAN_A, top1);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, top2);
  }
}

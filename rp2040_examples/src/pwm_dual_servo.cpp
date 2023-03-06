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
  auto const servo_min = max / 40u;
  auto const servo_max = servo_min + ( max / 20u + max / 30u );
  auto const servo_center = (servo_min + servo_max) / 2u;

  pwm_set_wrap(slice_num, max);                     // period
  pwm_set_chan_level(slice_num, PWM_CHAN_A, servo_center);
  pwm_set_chan_level(slice_num, PWM_CHAN_B, servo_center);

  pwm_set_enabled(slice_num, true);

  // make PWM nicely float, at different speeds
  while(true)
  {
    for(auto level=servo_min; level<servo_max; level+=10)
    {
      sleep_ms(20);
      pwm_set_chan_level(slice_num, PWM_CHAN_B, level);
    }
  }
}

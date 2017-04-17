#include <array>
#include "common.hpp"

struct Filter
{
  Filter(): lut_{ make() } { }

  auto operator()(const char c) const
  {
    const auto index = (uint8_t)c;
    return lut_[index];
  }

private:
  static std::array<bool, 256> make()
  {
    std::array<bool, 256> lut;
    for(auto& e: lut)
      e = false;
    lut['J'] = true;
    lut['u'] = true;
    lut['s'] = true;
    lut['t'] = true;
    lut[' '] = true;
    lut['C'] = true;
    lut['h'] = true;
    lut['e'] = true;
    lut['c'] = true;
    lut['k'] = true;
    lut['i'] = true;
    lut['n'] = true;
    lut['g'] = true;
    return lut;
  }
  const std::array<bool, 256> lut_;
};

int main()
{
  test( Filter{} );
}

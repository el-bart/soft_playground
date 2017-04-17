#include <array>
#include "common.hpp"

auto makeLut()
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

static const auto g_lut = makeLut();

auto filter(const char c)
{
  const auto index = (uint8_t)c;
  return g_lut[index];
}


int main()
{
  test(filter);
}

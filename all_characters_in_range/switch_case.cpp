#include "common.hpp"

auto filter(const char c)
{
  switch(c)
  {
    case 'J':
    case 'u':
    case 's':
    case 't':
    case ' ':
    case 'C':
    case 'h':
    case 'e':
    case 'c':
    case 'k':
    case 'i':
    case 'n':
    case 'g':
      return true;
    default:
      return false;
  }
}

int main()
{
  test(filter);
}

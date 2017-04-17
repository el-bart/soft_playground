#include "common.hpp"

auto filter(const char c)
{
  if( c == 'J' ) return true;
  if( c == 'u' ) return true;
  if( c == 's' ) return true;
  if( c == 't' ) return true;
  if( c == ' ' ) return true;
  if( c == 'C' ) return true;
  if( c == 'h' ) return true;
  if( c == 'e' ) return true;
  if( c == 'c' ) return true;
  if( c == 'k' ) return true;
  if( c == 'i' ) return true;
  if( c == 'n' ) return true;
  if( c == 'g' ) return true;

  return false;
}

int main()
{
  test(filter);
}

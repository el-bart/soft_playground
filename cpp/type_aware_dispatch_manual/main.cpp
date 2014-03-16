#include <iostream>
#include <stdexcept>
#include "Msgs.hpp"
#include "Dispatcher.hpp"
#include "MyDispatcher.hpp"

using namespace std;

int main(void)
{
  Msg1 m1;
  MyDispatcher md;

  md.dispatch( serialize(m1) );
}

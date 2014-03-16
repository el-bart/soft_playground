#include <iostream>
#include <stdexcept>
#include "Msgs.hpp"
#include "Dispatcher.hpp"
#include "MyDispatcher.hpp"
#include "sendAll.hpp"

using namespace std;

int main(void)
{
  Msg1 m1;
  MyDispatcher md;

  md.dispatch( serialize(m1) );

  for(unsigned i=0; i<1000; ++i)
    sendAll<250>(md);
}

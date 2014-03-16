#include <iostream>
#include "Msgs/Msg1.hpp"
#include "Dispatcher.hpp"

struct MyDispatcher: public CustomDispatcher<MyDispatcher, Msg1>
{
};

int main(void)
{
  MyDispatcher md;
}

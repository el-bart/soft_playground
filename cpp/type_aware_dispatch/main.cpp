#include <iostream>
#include "Msgs/Msg1.hpp"
#include "Dispatcher.hpp"

using namespace std;

struct MyDispatcher: public CustomDispatcher<MyDispatcher, Msg1>
{
  void handle(Msg1 const& msg)
  {
    cout << __PRETTY_FUNCTION__ << ": " << Msg1::type() <<endl;
  }
};

int main(void)
{
  Msg1 m1;
  MyDispatcher md;

  md.dispatch( serialize(m1) );
}

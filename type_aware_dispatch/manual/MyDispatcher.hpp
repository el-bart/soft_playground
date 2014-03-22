#pragma once

#include <iostream>
#include <stdexcept>

#include "Msgs.hpp"
#include "Dispatcher.hpp"

struct MyDispatcher: public Dispatcher
{
  template<unsigned N, unsigned S>
  void handle(Msg<N,S> const& msg) { std::cout << __PRETTY_FUNCTION__ << ": " << Msg<N,S>::type() << std::endl; }

  virtual void dispatch(BinaryMsg const& bin);
};

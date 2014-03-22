#pragma once

#include "BinaryMsg.hpp"


struct Dispatcher
{
  virtual ~Dispatcher(void) { }
  virtual void dispatch(BinaryMsg const& bin) = 0;
protected:
};

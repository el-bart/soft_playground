#pragma once

#include <cassert>
#include <boost/cast.hpp>

#include "BinaryMsg.hpp"


struct Handler
{
  virtual void handle(BinaryMsg const& bin) = 0;

protected:
  ~Handler(void) { }
};


template<typename FinalType, typename M>
struct Handle: public Handler
{
  template<typename D>
  explicit Handle(D& d)
  {
    d.handlers_[M::type()] = this;
  }

  virtual void handle(BinaryMsg const& bin)
  {
    assert( bin.type_ == M::type() );
    auto  tmp = bin;
    M&    msg = *reinterpret_cast<M*>(tmp.data_.data());
    auto* h   = boost::polymorphic_downcast<FinalType*>(this);
    assert(h);
    h->handle(msg);
  }
};

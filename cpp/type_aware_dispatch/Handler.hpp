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
struct Handle
{
  explicit Handle(FinalType& ft)
  {
    ft.handlers_[M::type()] = this;
  }

  virtual void handle(BinaryMsg const& bin)
  {
    assert( bin.type_ == M::type() );
    M&   msg = *static_cast<M*>(bin.data_.data());
    auto h   = boost::polymorphic_downcast<FinalType>(this);
    assert(h);
    h->handle(msg);
  }
};

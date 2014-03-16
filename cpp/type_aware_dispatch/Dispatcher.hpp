#pragma once

#include <unordered_map>

#include "BinaryMsg.hpp"
#include "Handler.hpp"


struct Dispatcher
{
  void dispatch(BinaryMsg const& bin)
  {
    auto it = handlers_.find(bin.type_);
    if(it==std::end(handlers_))
      throw std::runtime_error("no handler for a given message type");
    auto h = it->second;
    assert(h);
    h->handle(bin);
  }

  std::unordered_map<unsigned, Handler*> handlers_;

protected:
  ~Dispatcher(void) { }
};


template<typename FinalType, typename ...M>
struct CustomDispatcher: public Dispatcher,
                         public Handle<FinalType, M>...
{
  CustomDispatcher(void):
    Handle<FinalType, M>(*this)...
  {
  }
};

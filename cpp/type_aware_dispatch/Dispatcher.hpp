#pragma once

#include <unordered_map>
#include <boost/cast.hpp>

#include "BinaryMsg.hpp"


struct Dispatcher
{
  virtual ~Dispatcher(void) { }
  virtual void dispatch(BinaryMsg const& bin) = 0;
protected:
};


namespace detail
{
template<typename FinalType, typename C, typename H, typename ...T>
struct RegistrationHelper
{
  static void call(C& c)
  {
    auto h = [](FinalType& ft, BinaryMsg const& bin) { ft.handle( deserialize<H>(bin) ); };
    c[H::type()] = +h;
    RegistrationHelper<FinalType, C, T...>::call(c);
  }
};

template<typename FinalType, typename C>
struct RegistrationHelper<FinalType, C, void>
{
  static void call(C& c) { }
};
}


template<typename FinalType, typename ...M>
struct CustomDispatcher: public Dispatcher
{
  CustomDispatcher(void)
  {
    detail::RegistrationHelper<FinalType, decltype(handlers_), M..., void>::call(handlers_);
  }

  virtual void dispatch(BinaryMsg const& bin)
  {
    auto it = handlers_.find(bin.type_);
    if(it==std::end(handlers_))
      throw std::runtime_error("no handler for a given message type");
    auto h = it->second;
    assert(h);
    (*h)( *boost::polymorphic_downcast<FinalType*>(this), bin );
  }

private:
  std::unordered_map<unsigned, void(*)(FinalType&, BinaryMsg const&)> handlers_;
};

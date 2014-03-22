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

template<typename FinalType, typename M>
void todo(FinalType& ft, BinaryMsg const& bin)
{
  ft.handle( deserialize<M>(bin) );
}

template<typename FinalType, typename C, typename H, typename ...T>
struct RegistrationHelper
{
  static void call(C& c)
  {
    // NOTE: although lambda version is way nicer, GCC generates 6x bigger code for that, clang 2x.
    //       apparently both misse some important optimization. too bad... :(
#if 0
    c[H::type()] = +[](FinalType& ft, BinaryMsg const& bin) { ft.handle( deserialize<H>(bin) ); };
#else
    c[H::type()] = todo<FinalType,H>;
#endif
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
    // NOTE: compile time check for unique type-ids can be added here!
    detail::RegistrationHelper<FinalType, decltype(handlers_), M..., void>::call(handlers_);
    assert( handlers_.size() == sizeof...(M) && "non-unique message ids detected" );
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

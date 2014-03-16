#pragma once

#include "Msgs.hpp"
#include "BinaryMsg.hpp"

namespace detail
{
template<unsigned I, unsigned N>
struct Sender
{
  template<typename D>
  static void send(D& d)
  {
    Msg<I,I+4> m;
    d.dispatch( serialize(m) );
    Sender<I+1,N>::send(d);
  }
};

template<unsigned N>
struct Sender<N,N>
{
  template<typename D>
  static void send(D& d) { }
};
}

template<unsigned N, typename D>
void sendAll(D& d)
{
  detail::Sender<1, N+1>::send(d);
}

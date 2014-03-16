#pragma once

#include <vector>
#include <cstring>
#include <cassert>


struct BinaryMsg
{
  unsigned          type_;
  std::vector<char> data_;
};


template<typename M>
BinaryMsg serialize(M const& m)
{
  BinaryMsg b;
  b.type_ = M::type();
  b.data_.resize(sizeof(m));
  memcpy(b.data_.data(), &m, sizeof(m));
  return b;
}


template<typename M>
M deserialize(BinaryMsg const& b)
{
  M m;
  assert( M::type() == b.type_ );
  if( b.data_.size() != sizeof(m) )
    throw std::runtime_error("invalid payload size");
  memcpy(&m, b.data_.data(), sizeof(m));
  return m;
}

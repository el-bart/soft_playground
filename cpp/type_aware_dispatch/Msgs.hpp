#pragma once

template<unsigned N, unsigned S>
struct Msg
{
  static constexpr unsigned type() { return N; }

  char data_[S];
};

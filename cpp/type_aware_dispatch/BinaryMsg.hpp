#pragma once

#include <vector>

struct BinaryMsg
{
  unsigned          type_;
  std::vector<char> data_;
};

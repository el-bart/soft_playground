#include <vector>
#include <memory>
#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;

void wait(char const* str)
{
  cout << "brk=" << sbrk(0) << " on " << str << " - waiting for key... ";
  char c;
  cin >> c;
  (void)c;
}

int main()
{
  wait("init");

  constexpr auto kb   = 1024ul;
  constexpr auto mb   = 1024ul*kb;
  constexpr auto gb   = 1024ul*mb;
  constexpr auto size = 4ul*gb;

#if 1
  // will use mmap():
  constexpr auto block = 1ul*mb;
#else
  // will use brk()/sbrk():
  constexpr auto block = 100ul*kb;
#endif

  std::vector<std::unique_ptr<char[]>> blocks;
  const auto blocksCount = size/block;
  blocks.resize(blocksCount);
  for(auto i=0lu; i<blocksCount; ++i)
  {
    decltype(blocks)::value_type tmp{ new char[block] };
    memset( tmp.get(), 0, block );
    blocks.push_back( std::move(tmp) );
  }

  wait("post-memory allocation");

  decltype(blocks)::value_type max;
  for(auto& e: blocks)
    if( e.get() > max.get() )
      max = std::move(e);
  blocks.clear();

  wait("waiting to end the program");

  max.reset();

  wait("no more data");
}

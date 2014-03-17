//
// implemented by BaSz @ 2013/q2
//
// g++-4.7 -Wall -std=c++11 -O3 -DNDEBUG -march=native -o vector_vs_list.out vector_vs_list.cpp
//
#include <list>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cinttypes>
#include <cassert>

using namespace std;

typedef chrono::high_resolution_clock Clock;

typedef std::list<uint64_t>   List;
typedef std::vector<uint64_t> Vector;


template<typename C, typename R>
uint64_t algo(R r, const uint64_t n)
{
  C                      c;
  typename C::value_type out = 0;

  // insertion
  for(uint64_t i=0; i<n; ++i)
  {
    const auto x  = r();
    auto       it = c.begin();
    while( it!=c.end() && *it<x )
      ++it;
    c.insert(it, x);
    out+=x;
  }

  // sanity check
  assert( is_sorted( c.cbegin(), c.cend() ) );

  // removal
  for(uint64_t i=0; i<n; ++i)
  {
    const auto pos = r() % c.size();
    auto       it  = c.begin();
    for(uint64_t i=0; i<pos; ++i)
      ++it;
    out+=*it;
    c.erase(it);
  }

  return out;
}


template<typename C>
void run(const uint64_t n, const uint64_t seed)
{
  // prepare rand
  mt19937                            gen(seed);
  uniform_int_distribution<uint64_t> dist(0, n-1);
  auto                               r = [&]{ return dist(gen); };
  // work
  auto start = Clock::now();
  auto ret   = algo<C>(r, n);
  auto stop  = Clock::now();
  // info
  auto diff  = stop-start;
  cerr << typeid(C).name() << " = " << fixed << setprecision(3)
       << chrono::duration_cast<chrono::microseconds>(diff).count()/(1000*1000.0)
       << " [s] (xxx==" << ret%10 << ")\t";
}


int main(void)
{
  // initilize generator with some seed
  std::random_device rd;
  const auto         initSeed = rd();
  mt19937            gen(initSeed);
  cerr << ">> initial seed = " << initSeed << endl;

  for(uint64_t n=0; n<10*1000*1000l; n+=2000)
  {
    const auto seed = gen();
    cerr << "N = " << n << "\t";
    run<List>  (n, seed);
    run<Vector>(n, seed);
    cerr << " \t (for seed " << seed << ")" << endl;
  }

  return 0;
}

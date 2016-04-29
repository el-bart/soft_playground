#include <iomanip>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <typeinfo>
#include <boost/lexical_cast.hpp>

using Clock = std::chrono::high_resolution_clock;
using std::cout;
using std::cerr;
using std::endl;

auto makeNumbers(const unsigned count)
{
  std::mt19937_64                  gen(42);
  constexpr auto                   range = 1000*1000;
  std::uniform_real_distribution<> prng(-range, +range);

  std::vector<std::string> out;
  out.reserve(count);
  for(auto i=0u; i<count; ++i)
    out.push_back( boost::lexical_cast<std::string>( prng(gen) ) );

  return out;
}


template<typename C, typename F>
void measure(C const& c, F&& convert)
{
  const auto start = Clock::now();

  double out = 0;
  for(const auto& e: c)
    out += convert(e);

  const auto stop = Clock::now();
  const auto us   = std::chrono::duration_cast<std::chrono::microseconds>( stop - start );

  if(true)
    for(auto const& str: { c.at(0).c_str(), "123456789.123456789", "1.2", "42", "0.13", "0.00000000001234" })
      cout << "example conversion: " << str << " -> " << std::setprecision(20) << convert(str) << endl;
  cout << "resulting value: " <<  std::setprecision(20) << out << endl;
  cout << "time: \t" << us.count() << "[us]" << endl;
}


double implBoost(std::string const& in)
{
  return boost::lexical_cast<double>(in);
}

double implScanf(std::string const& in)
{
  double out;
  sscanf( in.c_str(), "%lf", &out );
  return out;
}


double implManualNoSign(std::string::const_iterator begin, const std::string::const_iterator end)
{
  auto     it  = begin;
  uint64_t pre = 0;

  for(; it!=end; ++it)
  {
    if( !isdigit(*it) )
      break;
    pre *= 10;
    pre += *it-'0';
  }
  if(it==end)
    return pre;

  if( *it!='.' )
    throw std::runtime_error{"1: NaN..."};
  ++it;

  uint64_t div  = 1;
  uint64_t post = 0;
  for(; it!=end; ++it)
  {
    if( not isdigit(*it) )
      throw std::runtime_error{"2: NaN..."};
    post *= 10;
    post += *it-'0';
    div  *= 10;
  }

  return double(pre) + double(post)/double(div);
}

double implManual(std::string const& in)
{
  if( in.empty() )
    throw std::runtime_error{"2: NaN..."};

  switch(in[0])
  {
    case '-': return -1 * implManualNoSign( begin(in)+1, end(in) );
    case '+': return +1 * implManualNoSign( begin(in)+1, end(in) );
  }
  if( not isdigit(in[0]) )
    throw std::runtime_error{"3: NaN..."};

  return implManualNoSign( begin(in), end(in) );
}


int main()
{
  cout << std::fixed;

  cout << "preparing data... ";
  const auto in = makeNumbers(1000*1000);
  //const auto in = makeNumbers(5);
  cout << "done!" << endl;

  cout << "MANUAL:" << endl;
  measure(in, implManual);
  cout << endl;

  cout << "SCANF:" << endl;
  measure(in, implScanf);
  cout << endl;

  cout << "BOOST:" << endl;
  measure(in, implBoost);
  cout << endl;
}

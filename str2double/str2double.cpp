#include <iomanip>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
  //constexpr auto                   range = 1000l*1000l*1000l*1000l*1000l;
  //constexpr auto                   range = 1000*1000;
  constexpr auto                   range = 1;
  //constexpr auto                   range = 0.0001;
  std::uniform_real_distribution<> prng(-range, +range);

  std::vector<std::string> out;
  out.reserve(count);
  for(auto i=0u; i<count; ++i)
  {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(20) << prng(gen);
    out.push_back( oss.str() );
  }

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

  if(false)
    for(auto const& str: { c.at(0).c_str(), "123456789.123456789", "1.2", "42", "0.13", "0.00000000001234" })
      cout << "example conversion: " << str << " -> " << std::setprecision(20) << convert(str) << endl;
  cout << "resulting value: " <<  std::setprecision(20) << out << endl;
  cout << "time: \t" << us.count() << "[us]" << endl;
}


template<typename C, typename F>
void writeConvertedToFile(C const& c, F&& convert, std::string const& path)
{
  std::ofstream of;
  of.open(path);
  if( not of.is_open() )
    throw std::runtime_error{"failed to open " + path + " file"};
  for(const auto& e: c)
    of << e << " -> " << convert(e) << endl;
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


template<typename T>
double implManualNoSign(std::string::const_iterator begin, const std::string::const_iterator end)
{
  auto it  = begin;
  T    pre = 0;

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

  T div  = 1;
  T post = 0;
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

template<typename T>
double implManual(std::string const& in)
{
  if( in.empty() )
    throw std::runtime_error{"3: NaN..."};

  switch(in[0])
  {
    case '-': return -1 * implManualNoSign<T>( begin(in)+1, end(in) );
    case '.':
    case '+': return +1 * implManualNoSign<T>( begin(in)+1, end(in) );
  }
  if( not isdigit(in[0]) )
    throw std::runtime_error{"4: NaN..."};

  return implManualNoSign<T>( begin(in), end(in) );
}


template<typename C>
void saveToFile(C const& c)
{
  std::ofstream of;
  of.open("data.bc");
  if( not of.is_open() )
    throw std::runtime_error{"failed to open file"};

  of << "#!/usr/bin/bc -ql" << endl;
  of << "scale = 100" << endl;
  of << "out = 0" << endl;
  for(auto& e: c)
    of << "out += " << e << endl;
  of << "out" << endl;
  of << "quit" << endl;
}


int main()
{
  cout << std::fixed;

  cout << "preparing data... ";
  cout.flush();
  const auto in = makeNumbers(1000*1000);
  //const auto in = makeNumbers(5);
  cout << "done!" << endl;

  cout << "writing to file... ";
  cout.flush();
  saveToFile(in);
  cout << "done!" << endl;
  cout << endl;


  cout << "MANUAL<uint64_t>:" << endl;
  measure(in, implManual<uint64_t>);
  writeConvertedToFile(in, implManual<uint64_t>, "manual_uint64_t.log");
  cout << endl;

  cout << "MANUAL<double>:" << endl;
  measure(in, implManual<double>);
  writeConvertedToFile(in, implManual<double>, "manual_double.log");
  cout << endl;

  cout << "SCANF:" << endl;
  measure(in, implScanf);
  writeConvertedToFile(in, implScanf, "scanf.log");
  cout << endl;

  cout << "BOOST:" << endl;
  measure(in, implBoost);
  writeConvertedToFile(in, implBoost, "boost.log");
  cout << endl;
}

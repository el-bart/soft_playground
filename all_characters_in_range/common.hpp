#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include <iostream>

struct Timer
{
  using Clock = std::chrono::high_resolution_clock;

  Timer() = default;

  double elapsed() const
  {
    const auto now = Clock::now();
    const auto diff = now - start_;
    const auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(diff);
    return ns.count() / ( 1000.0*1000.0*1000.0 );
  }

private:
  const Clock::time_point start_{ Clock::now() };
};


auto generateTestData()
{
  std::cout << "generating pseudo-radnom sequence..." << std::endl;
  const Timer t;
  const auto seed = 42;
  std::mt19937 gen{seed};
  std::uniform_int_distribution<char> dist{32, 126};    // stick with printable ascii codes
  constexpr auto kB = 1024ul;
  constexpr auto MB = 1024ul * kB;
  constexpr auto GB = 1024ul * MB;
  constexpr auto count = 1ul * GB;
  std::string out;
  out.reserve(count);
  for(auto i=0ul; i<count; ++i)
    out.push_back( dist(gen) );
  std::cout << "done in " << t.elapsed() << "[s]" << std::endl;
  return out;
}


template<typename F>
void sanityCheck(F& f)
{
  const auto okChars = std::string{"Just Checking"};
  for(auto c=char{32}; c<char{127}; ++c)
  {
    const auto isOkChar = ( okChars.find(c) != std::string::npos );
    const auto funcRet = f(c);
    if( isOkChar != funcRet )
      throw std::logic_error{"test function is invalid"};
  }
}


template<typename F>
void test(F&& f)
{
  sanityCheck(f);

  const auto data = generateTestData();
  auto errors = std::string::size_type{0};

  const Timer t;
  for(auto c: data)
    errors += static_cast<unsigned>( f(c) );    // avoids branches here
  const auto elapsed = t.elapsed();

  std::cout << "got " << errors << " errors" << std::endl;
  std::cout << "elapsed " << std::fixed << std::setprecision(9) << elapsed << "[s]" << std::endl;
}

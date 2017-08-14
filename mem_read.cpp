#include <vector>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;
using Clock = high_resolution_clock;

constexpr auto KB = 1024ul;
constexpr auto MB = 1024ul*KB;
constexpr auto GB = 1024ul*MB;


void readTest(std::vector<unsigned char> const& data)
{
  auto out = 0u;
  const auto start = Clock::now();
  for(auto& e: data)
    out += e;
  const auto stop  = Clock::now();
  const auto ms    = duration_cast<milliseconds>(stop-start);
  cout << "read of " << data.size()/GB << "[GB] in " << ms.count() << "[ms] (got: " << out << ") "
       << 1000.0 * (data.size()/GB) / double(ms.count()) << "[GB/s]" << endl;
}


void writeTest(std::vector<unsigned char>& data)
{
  const auto v = data[0]+1;
  const auto start = Clock::now();
  for(auto& e: data)
    e = v;
  const auto stop  = Clock::now();
  const auto ms    = duration_cast<milliseconds>(stop-start);
  cout << "write of " << data.size()/GB << "[GB] in " << ms.count() << "[ms] "
       << 1000.0 * (data.size()/GB) / double(ms.count()) << "[GB/s]" << endl;
}


int main()
{
  vector<unsigned char> data(8*GB);

  while(true)
  {
    cout << "------------------------------" << endl;
    writeTest(data);
    readTest(data);
  }
}

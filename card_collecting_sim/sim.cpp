#include <vector>
#include <random>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include <cassert>

using std::cerr;
using std::cout;

struct SimRes
{
  explicit SimRes(unsigned uniqueCardsCount):
    cards_(uniqueCardsCount, 0)
  { }

  std::vector<unsigned> cards_;
  unsigned iterations_{0};
  double totalCost_{0};
};


auto hasAllCards(std::vector<unsigned> const& cards, unsigned const playersCount)
{
  auto const present = [playersCount](auto c) { return c >= playersCount; };
  return std::all_of( begin(cards), end(cards), present );
}

template<typename F>
auto simulateOne(F&& randCard, unsigned const playersCount, unsigned const uniqueCardsCount, unsigned const cardsPerPack, double const packPrice)
{
  SimRes sr{uniqueCardsCount};
  do
  {
    ++sr.iterations_;
    sr.totalCost_ += packPrice;
    for(auto i = 0u; i < cardsPerPack; ++i)
    {
      auto const pos = randCard();
      assert( sr.cards_.size() > pos );
      ++sr.cards_[pos];
    }
  }
  while( not hasAllCards(sr.cards_, playersCount) );
  return sr;
}


struct SimHist
{
  auto averageCards(std::vector<unsigned> const& cards)
  {
    return std::accumulate( begin(cards), end(cards), 0.0 ) / cards.size();
  }

  void update(SimRes const& sr)
  {
    if(hist_.size() <= sr.iterations_)
      hist_.resize(sr.iterations_ + 1u);
    assert( hist_.size() > sr.iterations_ );
    auto& e = hist_[ sr.iterations_ ];
    ++e.samples_;
    if(e.samples_ == 1)
    {
      e.totalPrice_ = sr.totalCost_;
      e.averageCards_ = averageCards(sr.cards_);
    }
  }

  struct Entry
  {
    unsigned samples_{0};
    double totalPrice_{0};
    double averageCards_{0};
  };

  std::vector<Entry> hist_;
};


template<typename F>
auto simulate(F&& randCard, unsigned const playersCount, unsigned const uniqueCardsCount, unsigned const cardsPerPack, double const packPrice, unsigned const simulations)
{
  SimHist hist;
  for(auto i = 0u; i < simulations; ++i)
  {
    auto const res = simulateOne(randCard, playersCount, uniqueCardsCount, cardsPerPack, packPrice);
    hist.update(res);
  }
  return hist;
}


void printCsv(SimHist sh)
{
  cout << "# iteration  samples  samplesIntegral  totalPrice  cardsAvg\n";
  auto iteration = 0u;
  auto samplesIntegral = 0u;
  for(auto& e: sh.hist_)
  {
    samplesIntegral += e.samples_;
    cout
      << std::fixed << std::setprecision(2) << iteration << "\t"
      << std::fixed << std::setprecision(2) << e.samples_ << "\t"
      << std::fixed << std::setprecision(2) << samplesIntegral << "\t"
      << std::fixed << std::setprecision(2) << e.totalPrice_ << "\t"
      << std::fixed << std::setprecision(2) << e.averageCards_ << "\n";
    ++iteration;
  }
}


int main(int argc, char** argv)
{
  if( argc != 1 + 5 )
  {
    cerr << argv[0] << " <players_count> <unique_cards_count> <cards_per_pack> <pack_price> <simulations>\n";
    return 2;
  }

  auto const playersCount = boost::lexical_cast<unsigned>(argv[1]);
  auto const uniqueCardsCount = boost::lexical_cast<unsigned>(argv[2]);
  auto const cardsPerPack = boost::lexical_cast<unsigned>(argv[3]);
  auto const packPrice = boost::lexical_cast<double>(argv[4]);
  auto const simulations = boost::lexical_cast<unsigned>(argv[5]);

  std::mt19937 gen{ std::random_device{}() };
  std::uniform_int_distribution dist{0u, uniqueCardsCount-1u};
  auto randCard = [&] { return dist(gen); };

  auto const simHist = simulate(randCard, playersCount, uniqueCardsCount, cardsPerPack, packPrice, simulations);
  printCsv(simHist);
}

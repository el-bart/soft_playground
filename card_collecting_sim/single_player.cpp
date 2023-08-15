#include <vector>
#include <random>
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


auto hasAllCards(std::vector<unsigned> const& cards)
{
  auto const present = [](auto c) { return c > 0u; };
  return std::all_of( begin(cards), end(cards), present );
}

template<typename F>
auto simulateOne(F&& randCard, unsigned const uniqueCardsCount, unsigned const cardsPerPack, double const packPrice)
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
  while( not hasAllCards(sr.cards_) );
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
auto simulate(F&& randCard, unsigned const uniqueCardsCount, unsigned const cardsPerPack, double const packPrice, unsigned const simulations)
{
  SimHist hist;
  for(auto i = 0u; i < simulations; ++i)
  {
    auto const res = simulateOne(randCard, uniqueCardsCount, cardsPerPack, packPrice);
    hist.update(res);
  }
  return hist;
}


void printCsv(SimHist sh)
{
  cout << "iteration, samples, totalPrice, cardsAvg\n";
  auto iteration = 0u;
  for(auto& e: sh.hist_)
  {
    cout << iteration << ", " << e.samples_ << ", " << e.totalPrice_ << ", " << e.averageCards_ << "\n";
    ++iteration;
  }
}


int main(int argc, char** argv)
{
  if( argc != 1 + 4 )
  {
    cerr << argv[0] << " <unique_cards_count> <cards_per_pack> <pack_price> <simulations>\n";
    return 2;
  }

  auto const uniqueCardsCount = boost::lexical_cast<unsigned>(argv[1]);
  auto const cardsPerPack = boost::lexical_cast<unsigned>(argv[2]);
  auto const packPrice = boost::lexical_cast<double>(argv[3]);
  auto const simulations = boost::lexical_cast<unsigned>(argv[4]);

  std::mt19937 gen{ std::random_device{}() };
  std::uniform_int_distribution dist{0u, uniqueCardsCount-1u};
  auto randCard = [&] { return dist(gen); };

  auto const simHist = simulate(randCard, uniqueCardsCount, cardsPerPack, packPrice, simulations);
  printCsv(simHist);
}

#include <iostream>

using namespace std;


template<typename E>
struct Extractor
{
  template<typename T>
  static E go(T)
  {
    return E{};
  }

  template<typename ...Tail>
  static E go(E e, Tail...t)
  {
    return e;
  }

  template<typename Head, typename ...Tail>
  static E go(Head, Tail...t)
  {
    return go(t...);
  }
};


int main(void)
{
  const auto e = Extractor<float>::go(12, 34, /*3.14159f,*/ "x", 3.1);
  cout << e << endl;
  return 0;
}

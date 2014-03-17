#include <iostream>

using namespace std;


template<typename T>
int extract(void)
{
    return 0;
}

template<typename T, typename ...Tail>
int extract(Tail...t)
{
    return extract<T, Tail...>(t...);
}

template<typename T, typename Head, typename ...Tail>
int extract(Head h, Tail...t)
{
    return 1+extract<T, Tail...>(t...);
}


int main(void)
{
  const auto e = extract<int>(12, 34, "x", 3.1);
  cout << e << endl;
  return 0;
}

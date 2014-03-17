#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T>
T printOne(T t)
{
  cout << typeid(t).name() << " -> " << t << endl;
  return t;
}

template<typename ...Args>
void dummy(Args...) { }

template<typename ...Args>
void other(Args...a)
{
  dummy( printOne(a)... );
}

template<typename ...Args>
void doSth(Args...a)
{
  other("home", a..., "end");
}

int main(void)
{
  doSth(1, 3.14);
  return 0;
}

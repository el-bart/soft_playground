#include <iostream>

using namespace std;

template<typename E>
struct extract
{
  template<typename T>
  explicit extract(T t):
    default_{t}
  { }

  E from(void)
  {
    return default_;
  }
  template<typename ...Tail>
  E from(E e, Tail...)
  {
    return e;
  }
  template<typename Head, typename ...Tail>
  E from(Head, Tail...t)
  {
    return from(t...);
  }

private:
  E default_;
};


struct MyClass
{
  MyClass(void) { cout << __PRETTY_FUNCTION__ << endl; }
  ~MyClass(void) { cout << __PRETTY_FUNCTION__ << endl; }

  MyClass(MyClass const&) { cout << __PRETTY_FUNCTION__ << endl; }
  MyClass operator=(MyClass const&) { cout << __PRETTY_FUNCTION__ << endl; return *this; }

  MyClass(MyClass &&) { cout << __PRETTY_FUNCTION__ << endl; }
  MyClass operator=(MyClass &&) { cout << __PRETTY_FUNCTION__ << endl; return *this; }
};


class Conn
{
public:
  struct Host { std::string value_; };
  struct User { std::string value_; };
  struct Pass { std::string value_; };
  struct UseSSL { bool value_; };
  struct RetryCount { unsigned value_; };

  template<typename ...Args>
  explicit Conn(Args...a):
    host_( extract<Host>("my.db.org").from(a...).value_ ),
    user_( extract<User>("john").from(a...).value_ ),
    pass_( extract<Pass>("doe1940").from(a...).value_ ),
    useSSL_( extract<UseSSL>(false).from(a...).value_ ),
    retCnt_( extract<RetryCount>(10u).from(a...).value_ ),
    my_( extract<MyClass>(MyClass{}).from(a...) )
  { }

  void printCfg(void)
  {
    cout << "H=" << host_ << endl;
    cout << "U=" << user_ << endl;
    cout << "P=" << pass_ << endl;
    cout << "S=" << (useSSL_?"SSL":"plain text") << endl;
    cout << "R=" << retCnt_ << endl;
  }

private:
  decltype(Host::value_)       host_;
  decltype(User::value_)       user_;
  decltype(Pass::value_)       pass_;
  decltype(UseSSL::value_)     useSSL_;
  decltype(RetryCount::value_) retCnt_;
  MyClass                      my_;
};


struct A { int a; };

int main(void)
{
  auto v = extract<float>(0.99f).from(666, 1.24, 3.14, 2.72f, 42);
  cout << "Extracted: " << v << endl;

  {
    cout << "1 ----------" << endl;
    Conn c;
    c.printCfg();
  }
  {
    cout << "2 ----------" << endl;
    Conn c( Conn::UseSSL{true}, Conn::User{"alice"}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }
  {
    cout << "3 ----------" << endl;
    Conn c( Conn::Host{"other.db.host.org"} );
    c.printCfg();
  }
  {
    cout << "4 ----------" << endl;
    Conn c( Conn::Host{"other.db.host.org"}, MyClass{} );
    c.printCfg();
  }
  {
    cout << "5 ----------" << endl;
    Conn c( MyClass{}, Conn::UseSSL{true}, Conn::User{"alice"}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }

  return 0;
}

#include <iostream>
#include <algorithm>
#include <type_traits>

using namespace std;


/** @brief type signalling that there is no default value present for a given parameter. */
struct NoDefaultValue {};


/** @brief extractor template - gets the value of a given paramter. */
template<typename E>
struct extract
{
  /** @brief extracts type E from the Args argument list, default value or compilation error. */
  template<typename...Args>
  static E from(Args&&...args)
  {
    ensureUnique( std::forward<Args&&>(args)... );      // sanity check
    return fromImpl( std::forward<Args&&>(args)... );   // actuall implementation
  };

private:
  /** @brief short for remove_cv and decay on a given type. */
  template<typename T>
  struct Raw
  {
    typedef typename remove_cv<typename decay<T>::type>::type type;
  };

  //
  // counts number of occurences of given type C in the argument list.
  //
  template<typename C, typename Head, typename...Tail>
  static constexpr size_t count(void)
  {
    return (is_same< typename Raw<C>::type,
                     typename Raw<Head>::type >::value?1:0)
            +
            count<C,Tail...>();
  }
  template<typename C>
  static constexpr size_t count(void)
  {
    return 0;
  }

  //
  // extraction itself
  //
  /** @brief template used for signalling missing parameter of a given type. */
  template<typename T>
  constexpr bool missingParameter(void) { return false; }
  /** @brief causes compilation error when required parameter is not supplied. */
  static E fromImpl(NoDefaultValue&&)
  {
    static_assert( missingParameter<E>(), "missing paramter with no default value: " );
  }
  /** @brief created default agrument, using user-provided functor. */
  template<typename F>
  static E fromImpl(F&& f)
  {
    return f();
  }
  /** @brief extractor of a given paramter, when it has been found. */
  template<typename Head, typename ...Tail>
  static
  typename enable_if< is_same< typename Raw<Head>::type, E >::value, E >::type
  fromImpl(Head&& e, Tail&&...)
  {
    return std::forward<Head&&>(e);
  }
  /** @brief general search - no proper value found yet. */
  template<typename Head, typename ...Tail>
  static
  typename enable_if< !is_same< typename Raw<Head>::type, E >::value, E >::type
  fromImpl(Head&&, Tail&&...t)
  {
    return fromImpl(std::forward<Tail&&>(t)...);
  }

  //
  // wrapper call that ensures all arguments are unique.
  //
  template<typename Head, typename...Tail>
  static void ensureUnique(Head&& head, Tail&&...tail)
  {
    static_assert( count<Head,Tail...>() <= 0, "argument is repeated" );    // check current one
    ensureUnique( std::forward<Tail&&>(tail)... );                          // check next
  };
  static void ensureUnique(void) { }

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


/** @brief declares c-tor of the class with the named parameters. */
#define BNP_CONSTRUCTOR(name) template<typename ...Args> explicit name(Args&&...a)

/** @brief declares new paramter type. */
#define BNP_MK_PARAM(name, type) struct name { type value_; operator type&&(void) { return std::move(value_); } }
/** @brief gets the underlying type from the parameter wrapper. */
#define BNP_PARAM_TYPE(type) decltype(type::value_)

/** @brief extracts given paramter via the type. */
#define BNP_EXTRACT(type)           extract<type>::from( std::forward<Args&&>(a)..., NoDefaultValue{}           )
/** @brief the same as BNP_EXTRACT but with the explicitly provided default value. */
#define BNP_EXTRACT_D(type, defVal) extract<type>::from( std::forward<Args&&>(a)..., [](){return type{defVal};} )
/** @brief the same as BNP_EXTRACT but informing that the default c-tor is to be used for default value. */
#define BNP_EXTRACT_DC(type)        extract<type>::from( std::forward<Args&&>(a)..., [](){return type{};}       )

class Conn
{
public:
  BNP_MK_PARAM(Host, std::string);
  BNP_MK_PARAM(User, std::string);
  BNP_MK_PARAM(Pass, std::string);
  BNP_MK_PARAM(UseSSL, bool);
  BNP_MK_PARAM(RetryCount, unsigned);
  // NOTE: no declaration for user's unique type

  /*
  template<typename ...Args>
  explicit Conn(Args&&...a):
   */
  BNP_CONSTRUCTOR(Conn):
    host_( BNP_EXTRACT_D(Host, "my.db.org") ),
    user_( BNP_EXTRACT_D(User, "john") ),
    pass_( BNP_EXTRACT_D(Pass, "doe1940") ),
    useSSL_( BNP_EXTRACT_D(UseSSL, false) ),
    retCnt_( BNP_EXTRACT_D(RetryCount, 10u) ),
    my_( BNP_EXTRACT_DC(MyClass) )
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
  BNP_PARAM_TYPE(Host)       host_;
  BNP_PARAM_TYPE(User)       user_;
  BNP_PARAM_TYPE(Pass)       pass_;
  BNP_PARAM_TYPE(UseSSL)     useSSL_;
  BNP_PARAM_TYPE(RetryCount) retCnt_;;
  MyClass                    my_;
};


int main(void)
{
  auto v = extract<float>::from(666, 3.14, 2.72f, char{42});
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
  {
    cout << "6 ----------" << endl;
    MyClass mc;
    Conn c( Conn::UseSSL{true}, mc, Conn::User{"alice"}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }
  {
    cout << "7 ----------" << endl;
    const MyClass mc;
    Conn c( Conn::UseSSL{true}, mc, Conn::User{"alice"}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }
#if 0
  {
    cout << "8 ----------" << endl;
    const Conn::UseSSL ssl{true};
    Conn c( ssl, Conn::UseSSL{true}, Conn::User{"alice"}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }
#endif
#if 0
  {
    cout << "9 ----------" << endl;
    const MyClass mc;
    Conn c( Conn::UseSSL{true}, mc, Conn::User{"alice"}, MyClass{}, Conn::Pass{"$3cr37"} );
    c.printCfg();
  }
#endif

  return 0;
}

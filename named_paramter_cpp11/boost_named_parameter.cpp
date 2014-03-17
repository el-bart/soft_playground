#include <iostream>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>

using namespace std;


struct MyClass
{
  MyClass(void) { cout << __PRETTY_FUNCTION__ << endl; }
  ~MyClass(void) { cout << __PRETTY_FUNCTION__ << endl; }

  MyClass(MyClass const&) { cout << __PRETTY_FUNCTION__ << endl; }
  MyClass operator=(MyClass const&) { cout << __PRETTY_FUNCTION__ << endl; return *this; }

  MyClass(MyClass &&) { cout << __PRETTY_FUNCTION__ << endl; }
  MyClass operator=(MyClass &&) { cout << __PRETTY_FUNCTION__ << endl; return *this; }
};


BOOST_PARAMETER_NAME(width)    // Note: no semicolon
BOOST_PARAMETER_NAME(height)
BOOST_PARAMETER_NAME(my)
BOOST_PARAMETER_NAME(my2)


BOOST_PARAMETER_FUNCTION(
    (int),                // 1. parenthesized return type
    func2,    // 2. name of the function template
    tag,                   // 3. namespace of tag types
    (required (my, (int)) ) // 4. one required parameter, and
    (optional              //    four optional parameters, with defaults
     (width,  (int), 10)
     (height, (int), 20)
     (my2,    (MyClass), MyClass{})
    )
    )
{
  return width+height;
}

int func(int w, int h, MyClass mc)
{
  return w+h;
}



int main(void)
{
  //func2(1,2, MyClass{});
  {
    cout << "1 -------" << endl;
    func2(42, _my2=MyClass{});
  }
  {
    cout << "2 -------" << endl;
    func2(42);
  }
  return 0;
}

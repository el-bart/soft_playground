#include <string>
#include <iostream>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>

using namespace std;

BOOST_PARAMETER_NAME(foo)
BOOST_PARAMETER_NAME(bar)
BOOST_PARAMETER_NAME(baz)
BOOST_PARAMETER_NAME(bonk)

BOOST_PARAMETER_FUNCTION(
    (int),  // the return type of the function, the parentheses are required.
    function_with_named_parameters, // the name of the function.
    tag,  // part of the deep magic. If you use BOOST_PARAMETER_NAME you need to put "tag" here.
    (required // names and types of all required parameters, parentheses are required.
     (foo, (int))
     (bar, (float))
    )
    (optional // names, types, and default values of all optional parameters.
     (baz, (bool) , false)
     (bonk, (std::string), "default value")
    )
    )
{
  if (baz && (bar > 1.0))
    cout << foo << endl;;
  cout << bonk.size() << endl;;
  return 0;
}

int main(void)
{
  function_with_named_parameters(1, 10.0);
  function_with_named_parameters(7, _bar = 3.14);
  function_with_named_parameters( _bar = 0.0, _foo = 42);
  function_with_named_parameters( _bar = 2.5, _bonk= "Hello", _foo = 9);
  function_with_named_parameters(9, 2.5, true, "Hello");
  return 0;
}

#include "isvalid.hpp"
#include<iostream>
#include<string>
#include<utility>

int main()
{
  using namespace std;
  cout << boolalpha;

  // define to check for data member first:
  constexpr auto hasFirst
    = isValid([](auto x) -> decltype((void)valueT(x).first) {
              });

  cout << "hasFirst: " << hasFirst(type<pair<int,int>>) << '\n'; // true

  // define to check for member type size_type:
  constexpr auto hasSizeType
    = isValid([](auto x) -> typename decltype(valueT(x))::size_type {
              });

  struct CX {
    using size_type = std::size_t;
  };
  cout << "hasSizeType: " << hasSizeType(type<CX>) << '\n';      // true

  if constexpr(!hasSizeType(type<int>)) {
      cout << "int has no size_type\n";
      //...
  }

  // define to check for <:
  constexpr auto hasLess
    = isValid([](auto x, auto y) -> decltype(valueT(x) < valueT(y)) {
              });

  cout << hasLess(42, type<char>) << '\n';               // yields true
  cout << hasLess(type<string>, type<string>) << '\n';   // yields true
  cout << hasLess(type<string>, type<int>) << '\n';      // yields false
  cout << hasLess(type<string>, "hello") << '\n';        // yields true
}

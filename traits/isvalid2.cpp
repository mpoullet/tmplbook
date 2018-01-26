#include "isvalid.hpp"
#include<iostream>
#include<string>
#include<utility>

constexpr auto hasFirst
  = isValid([](auto&& x) -> decltype((void)&x.first) {
            });
template<typename T>
using HasFirstT = decltype(hasFirst(std::declval<T>()));

constexpr auto hasSizeType
  = isValid([](auto&& x)
             -> typename std::decay_t<decltype(x)>::size_type {
            });
template<typename T>
using HasSizeTypeT = decltype(hasSizeType(std::declval<T>()));

constexpr auto hasLess
  = isValid([](auto&& x, auto&& y) -> decltype(x < y) {
            });
template<typename T1, typename T2>
using HasLessT = decltype(hasLess(std::declval<T1>(), std::declval<T2>()));

int main()
{
  using namespace std;

  cout << "first: " << HasFirstT<pair<int,int>>::value << '\n'; // true

  struct CX {
    using size_type = std::size_t;
  };
  cout << "size_type: " << HasSizeTypeT<CX>::value << '\n';     // true
  cout << "size_type: " << HasSizeTypeT<int>::value << '\n';    // false

  cout << HasLessT<int, char>::value << '\n';                   // true
  cout << HasLessT<string, string>::value << '\n';              // true
  cout << HasLessT<string, int>::value << '\n';                 // false
  cout << HasLessT<string, char*>::value << '\n';               // true
}

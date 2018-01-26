#include <type_traits>
#include <iostream>

int main()
{
  using namespace std;
  cout << boolalpha;

  using MyType = int;
  cout << is_const<MyType>::value << '\n';  // prints false

  using VT = is_const<MyType>::value_type;  // bool
  using T = is_const<MyType>::type;         // integral_constant<bool,~false>
  cout << is_same<VT,bool>::value << '\n';  // prints true
  cout << is_same<T, integral_constant<bool, false>>::value
       << '\n';                             // prints true
  cout << is_same<T, bool_constant<false>>::value
       << '\n';                             // prints true (not valid
                                            // prior to C++17)

  auto ic = is_const<MyType>();             // object of trait type
  cout << is_same<decltype(ic), is_const<int>>::value << '\n';  // true
  cout << ic() << '\n';                     // function call (prints false)

  static constexpr auto mytypeIsConst = is_const<MyType>{};
  if constexpr(mytypeIsConst) {       // compile-time check since C++17 => false 
    //...                              // discarded statement
  }
  static_assert(!std::is_const<MyType>{}, "MyType should not be const"); 
}

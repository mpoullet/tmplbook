#include <type_traits>
#include <iostream>

int main()
{
   int i = 42;
   std::add_const<int>::type c = i;      // c is int const
   std::add_const_t<int> c14 = i;        // since C++14
   static_assert(std::is_const<decltype(c)>::value, "c should be const"); 

   std::cout << std::boolalpha;
   std::cout << std::is_same<decltype(c), int const>::value  // true
             << '\n';
   std::cout << std::is_same_v<decltype(c), int const>       // since C++17
             << '\n';
   if (std::is_same<decltype(c), int const>{}) {  // implicit conversion to bool
     std::cout << "same \n";
   }
}

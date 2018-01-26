#include <iostream>
#include "sqrt1.hpp"

int main()
{
  std::cout << "Sqrt<16>::value = " << Sqrt<16>::value << '\n';
  std::cout << "Sqrt<25>::value = " << Sqrt<25>::value << '\n';
  std::cout << "Sqrt<42>::value = " << Sqrt<42>::value << '\n';
  std::cout << "Sqrt<1>::value =  " << Sqrt<1>::value << '\n';
}

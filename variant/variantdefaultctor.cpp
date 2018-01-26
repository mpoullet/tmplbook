#include "variant-all.hpp"
#include <iostream>

int main()
{
  Variant<int, double> v;
  if (v.is<int>()) {
      std::cout << "Default-constructed v stores the int " 
                << v.get<int>() << '\n';
  }
  Variant<double, int> v2;
  if (v2.is<double>()) {
      std::cout << "Default-constructed v2 stores the double " 
                << v2.get<double>() << '\n';
  }
}

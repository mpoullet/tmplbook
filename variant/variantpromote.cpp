#include "variant-all.hpp"
#include <iostream>
#include <string>

int main() 
{
  Variant<short, float, char const*> v1((short)123);

  Variant<int, std::string, double> v2(v1);
  std::cout << "v2 contains the integer " << v2.get<int>() << '\n';

  v1 = 3.14f;
  Variant<double, int, std::string> v3(std::move(v1));
  std::cout << "v3 contains the double " << v3.get<double>() << '\n';

  v1 = "hello";
  Variant<double, int, std::string> v4(std::move(v1));
  std::cout << "v4 contains the string " << v4.get<std::string>() << '\n';
}

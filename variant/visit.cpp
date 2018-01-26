#include "variant.hpp"
#include <iostream>
#include <typeinfo>

int main()
{
  Variant<int, short, double, float> v(1.5);
  auto result = v.visit([](auto const& value) {
                          return value + 1;
                        });
  std::cout << typeid(result).name() << '\n';
}

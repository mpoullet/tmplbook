#include "myfirst.hpp"
#include <iostream>
#include <typeinfo>

// implementation/definition of template
template <typename T>
void printTypeof(T const& x) {
  std::cout << typeid(x).name() << '\n';
}

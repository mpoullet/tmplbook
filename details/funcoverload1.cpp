#include "funcoverload1.hpp"
#include <iostream>

int main() {
  std::cout << f<int*>((int*)nullptr);  // calls f<T>(T)
  std::cout << f<int>((int*)nullptr);   // calls f<T>(T*)
}

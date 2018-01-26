#include <algorithm>
#include "tupleelt1.hpp"
#include "tuplestorage3.hpp"
#include <iostream>

struct A {
   A() {
     std::cout << "A()" << '\n';
   }
};

struct B {
   B() {
     std::cout << "B()" << '\n';
   }
};

int main()
{
  Tuple<A, char, A, char, B> t1;
  std::cout << sizeof(t1) << " bytes" << '\n';
}

#include <iostream>
#include "isfunda.hpp"

template <typename T>
void test(T const&) {
  if (IsFundaT<T>::value) {
    std::cout << "T is a fundamental type" << '\n';
  } else {
    std::cout << "T is not a fundamental type" << '\n';
  }
}

int main() {
  test(7);
  test("hello");
}

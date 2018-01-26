#include <iostream>
#include <typeinfo>
#include <type_traits>
#include "decay.hpp"

template<typename T>
void printDecayedType()
{
  using A = typename DecayT<T>::Type;
  std::cout << "Parameter type: " << typeid(A).name() << '\n';
  std::cout << "- is int:     " << std::is_same<A,int>::value << '\n';
  std::cout << "- is const:   " << std::is_const<A>::value << '\n';
  std::cout << "- is pointer: " << std::is_pointer<A>::value << '\n';
}

int main()
{
  printDecayedType<int>();
  printDecayedType<int const>();
  printDecayedType<int[7]>();
  printDecayedType<int(int)>();
}

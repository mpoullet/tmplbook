#include <initializer_list>
#include <string>
#include <iostream>

template<typename T>
struct Array {
  Array(std::initializer_list<T>) {
    std::cout << "#1\n";
  }
  Array(unsigned n, T const&) {
    std::cout << "#2\n";
  }
};

void arr1(Array<int>) {
}

void arr2(Array<std::string>) {
}

int main()
{
  arr1({1, 2, 3, 4, 5});                     // prints \#1
  arr1({1, 2});                              // prints \#1
  arr1({10u, 5});                            // prints \#1
  arr2({"hello", "initializer", "list"});    // prints \#1
  arr2({10, "hello"});                       // prints \#2
}

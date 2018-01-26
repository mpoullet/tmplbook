#include <initializer_list>
#include <string>
#include <vector>
#include <complex>
#include <iostream>

void f(std::initializer_list<int>) {
  std::cout << "#1\n";
}

void f(std::initializer_list<std::string>) {
  std::cout << "#2\n";
}

void g(std::vector<int> const& vec) {
  std::cout << "#3\n";
}

void h(std::complex<double> const& cmplx) {
  std::cout << "#4\n";
}

struct Point {
  int x, y;
};
void i(Point const& pt) {
  std::cout << "#5\n";
}

int main()
{
  f({1, 2, 3});                         // prints \#1
  f({"hello", "initializer", "list"});  // prints \#2
  g({1, 1, 2, 3, 5});                   // prints \#3
  h({1.5, 2.5});                        // prints \#4
  i({1, 2});                            // prints \#5
}

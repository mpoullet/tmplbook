#include <string>
#include <iostream>

class C {
  public:
    C() = default;
    C (C const&) {
      std::cout << "copy constructor\n";
    }
    C (C&&) {
      std::cout << "move constructor\n";
    }
    template<typename T>
    C (T&&) {
      std::cout << "template constructor\n";
    }
};

int main() 
{
    C x;
    C x2{x};             // prints: template constructor
    C x3{std::move(x)};  // prints: move constructor
    C const c;
    C x4{c};             // prints: copy constructor
    C x5{std::move(c)};  // prints: template constructor
}

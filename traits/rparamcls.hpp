#include "rparam.hpp"
#include <iostream>

class MyClass1 {
  public:
    MyClass1 () {
    }
    MyClass1 (MyClass1 const&) {
        std::cout << "MyClass1 copy constructor called\n";
    }
};

class MyClass2 {
  public:
    MyClass2 () {
    }
    MyClass2 (MyClass2 const&) {
        std::cout << "MyClass2 copy constructor called\n";
    }
};

// pass MyClass2 objects with RParam<> by value
template<>
class RParam<MyClass2> {
  public:
    using Type = MyClass2;
};

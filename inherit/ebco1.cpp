#include <iostream>

class Empty {
  using Int = int;  // type alias members don't make a class nonempty
};

class EmptyToo : public Empty {
};

class EmptyThree : public EmptyToo {
};

int main()
{
  std::cout << "sizeof(Empty):      " << sizeof(Empty) << '\n';
  std::cout << "sizeof(EmptyToo):   " << sizeof(EmptyToo) << '\n';
  std::cout << "sizeof(EmptyThree): " << sizeof(EmptyThree) << '\n';
}

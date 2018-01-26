#include "stack9.hpp"
#include <iostream>
#include <vector>

int main()
{
  Stack<int>   iStack;     // stack of ints
  Stack<float> fStack;     // stack of floats

  // manipulate int stack
  iStack.push(1);
  iStack.push(2);
  std::cout << "iStack.top(): " << iStack.top() << '\n';

  // manipulate float stack:
  fStack.push(3.3);
  std::cout << "fStack.top(): " << fStack.top() << '\n';

  // assign stack of different type and manipulate again
  fStack = iStack;
  fStack.push(4.4);
  std::cout << "fStack.top(): " << fStack.top() << '\n';

  // stack for doubless using a vector as an internal container
  Stack<double, std::vector> vStack;
  vStack.push(5.5);
  vStack.push(6.6);
  std::cout << "vStack.top(): " << vStack.top() << '\n';

  vStack = fStack;
  std::cout << "vStack: ";
  while (! vStack.empty()) {
    std::cout << vStack.top() << ' ';
    vStack.pop();
  }
  std::cout << '\n';
}

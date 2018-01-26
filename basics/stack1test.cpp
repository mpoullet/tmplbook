#include "stack1.hpp"
#include <iostream>
#include <string>

int main()
{
  Stack<int>         intStack;       // stack of ints
  Stack<std::string> stringStack;    // stack of strings

  // manipulate int stack
  intStack.push(7);
  std::cout << intStack.top() << '\n';

  // manipulate string stack
  stringStack.push("hello");
  std::cout << stringStack.top() << '\n';
  stringStack.pop();
}

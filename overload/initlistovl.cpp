#include <initializer_list>
#include <iostream>

void ovl(std::initializer_list<char>) {   // \#1
  std::cout << "#1\n";
}

void ovl(std::initializer_list<int>) {    // \#2
  std::cout << "#2\n";
}

int main()
{
  ovl({'h', 'e', 'l', 'l', 'o', '\0'});  // prints \#1
  ovl({'h', 'e', 'l', 'l', 'o', 0});     // prints \#2
}

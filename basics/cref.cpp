#include <functional>  // for std::cref()
#include <string>
#include <iostream>

void printString(std::string const& s)
{
  std::cout << s << '\n';
}

template<typename T>
void printT (T arg)
{
  printString(arg);        // might convert arg back to std::string
}

int main()
{
  std::string s = "hello";
  printT(s);               // print s passed by value
  printT(std::cref(s));    // print s passed ``as if by reference''
}

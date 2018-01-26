#include <vector>
#include <iostream>

template<typename F>
void forUpTo(int n, F f)
{
  for (int i = 0; i != n; ++i)
  {
    f(i);  // call passed function f for i
  }
}

void printInt(int i)
{
  std::cout << i << ' ';  
}

int main()
{
  std::vector<int> values;

  // insert values from 0 to 4:
  forUpTo(5,
          [&values](int i) {
            values.push_back(i);
          });

  // print elements:
  forUpTo(5,
          printInt);    // prints 0 1 2 3 4
  std::cout << '\n';
}

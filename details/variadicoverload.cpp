#include <iostream>

template<typename T>
int f(T*)
{
  return 1;
}

template<typename... Ts>
int f(Ts...)
{
  return 2;
}

template<typename... Ts>
int f(Ts*...)
{
  return 3;
}

int main()
{
  std::cout << f(0, 0.0);                          // calls f<>(Ts...)
  std::cout << f((int*)nullptr, (double*)nullptr); // calls f<>(Ts*...)
  std::cout << f((int*)nullptr);                   // calls f<>(T*)
}

#include <iostream>

template<typename... Ts> class Tuple
{
};

template<typename T>
int f(Tuple<T*>)
{
  return 1;
}

template<typename... Ts>
int f(Tuple<Ts...>)
{
  return 2;
}

template<typename... Ts>
int f(Tuple<Ts*...>)
{
  return 3;
}

int main()
{
  std::cout << f(Tuple<int, double>());    // calls f<>(Tuple<Ts...>)
  std::cout << f(Tuple<int*, double*>());  // calls f<>(Tuple<Ts*...>)
  std::cout << f(Tuple<int*>());           // calls f<>(Tuple<T*>)
}

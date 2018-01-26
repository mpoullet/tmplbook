#include <initializer_list>

template<typename T> void f(std::initializer_list<T>);

int main()
{
  f({2, 3, 5, 7, 9});                // OK: T is deduced to int
  f({'a', 'e', 'i', 'o', 'u', 42});  // ERROR: T deduced to both char and int
}

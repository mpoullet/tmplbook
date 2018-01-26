#include <functional>

void forUpTo(int n, std::function<void(int)> f)
{
  for (int i = 0; i != n; ++i)
  {
    f(i);  // call passed function f for i
  }
}

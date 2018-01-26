void forUpTo(int n, void (*f)(int))
{
  for (int i = 0; i != n; ++i)
  {
    f(i);  // call passed function f for i
  }
}

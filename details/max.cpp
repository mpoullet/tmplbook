template<typename T> 
T max (T a, T b)
{
  return  b < a ? a : b;
}

int main()
{
  ::max<double>(1.0, -3.0);  // explicitly specify template argument
  ::max(1.0, -3.0);          // template argument is implicitly deduced to be double
  ::max<int>(1.0, 3.0);      // the explicit <int> inhibits the deduction;
                             // hence the result has type int
}


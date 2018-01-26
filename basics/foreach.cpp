#include <iostream>
#include <vector>
#include "foreach.hpp"

// a function to call:
void func(int i)
{
  std::cout << "func() called for: " << i << '\n';
}

// a function object type (for objects that can be used as functions):
class FuncObj {
  public:
    void operator() (int i) const {  // Note: const member function
      std::cout << "FuncObj::op() called for: " << i << '\n';
    }
};

int main()
{
  std::vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };

  foreach(primes.begin(), primes.end(),  // range
          func);                         // function as callable (decays to pointer)

  foreach(primes.begin(), primes.end(),  // range
          &func);                        // function pointer as callable

  foreach(primes.begin(), primes.end(),  // range
          FuncObj());                    // function object as callable

  foreach(primes.begin(), primes.end(),  // range
          [] (int i) {                   // lambda as callable
            std::cout << "lambda called for: " << i << '\n';
          });
}

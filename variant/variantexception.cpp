#include "variant-all.hpp"
#include <exception>
#include <iostream>
#include <string>

class CopiedNonCopyable : public std::exception
{
};

class NonCopyable
{
 public:
  NonCopyable() {
  }

  NonCopyable(NonCopyable const&) {
    throw CopiedNonCopyable();
  }

  NonCopyable(NonCopyable&&) = default;

  NonCopyable& operator= (NonCopyable const&) {
    throw CopiedNonCopyable();
  }

  NonCopyable& operator= (NonCopyable&&) = default;
};

int main() 
{
  Variant<int, NonCopyable> v(17);
  try {
    NonCopyable nc;
    v = nc;
  }
  catch (CopiedNonCopyable)  {
    std::cout << "Copy assignment of NonCopyable failed." << '\n';
    if (!v.is<int>() && !v.is<NonCopyable>()) {
      std::cout << "Variant has no value." << '\n';
    }
  }
}

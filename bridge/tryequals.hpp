#include <exception>
#include "isequalitycomparable.hpp"

template<typename T, 
         bool EqComparable = IsEqualityComparable<T>::value>
struct TryEquals 
{
  static bool equals(T const& x1, T const& x2) {
    return x1 == x2;
  }
};

class NotEqualityComparable : public std::exception
{
};

template<typename T>
struct TryEquals<T, false> 
{
  static bool equals(T const& x1, T const& x2) {
    throw NotEqualityComparable();
  }
};

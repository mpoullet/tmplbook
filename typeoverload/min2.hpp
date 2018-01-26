#include "isconvertible.hpp"
#include "lessresult.hpp"

template<typename T>
EnableIf<IsConvertible<LessResult<T const&, T const&>, bool>,
         T const&>
min(T const& x, T const& y)
{
  if (y < x) {
    return y;
  }
  return x;
}

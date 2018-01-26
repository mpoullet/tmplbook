#include "ifthenelse.hpp"

// primary template for main recursive step
template<int N, int LO=1, int HI=N>
struct Sqrt {
  // compute the midpoint, rounded up
  static constexpr auto mid = (LO+HI+1)/2;

  // search a not too large value in a halved interval
  using SubT = IfThenElse<(N<mid*mid),
                          Sqrt<N,LO,mid-1>,
                          Sqrt<N,mid,HI>>;
  static constexpr auto value = SubT::value;
};

// partial specialization for end of recursion criterion
template<int N, int S>
struct Sqrt<N, S, S> {
  static constexpr auto value = S;
};

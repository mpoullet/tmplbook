// primary template to compute sqrt(N)
template<int N, int LO=1, int HI=N>
struct Sqrt {
  // compute the midpoint, rounded up
  static constexpr auto mid = (LO+HI+1)/2;

  // search a not too large value in a halved interval
  static constexpr auto value = (N<mid*mid) ? Sqrt<N,LO,mid-1>::value
                                            : Sqrt<N,mid,HI>::value;
};

// partial specialization for the case when LO equals HI
template<int N, int M>
struct Sqrt<N,M,M> {
  static constexpr auto value = M;
};

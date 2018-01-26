// primary template to compute 3 to the Nth
template<int N>
struct Pow3 {
  static int const value = 3 * Pow3<N-1>::value;
};

// full specialization to end the recursion
template<>
struct Pow3<0> {
  static int const value = 1;
};

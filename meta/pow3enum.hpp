// primary template to compute 3 to the Nth
template<int N>
struct Pow3 {
  enum { value = 3 * Pow3<N-1>::value };
};

// full specialization to end the recursion
template<>
struct Pow3<0> {
  enum { value = 1 };
};

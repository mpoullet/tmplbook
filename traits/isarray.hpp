#include <cstddef>

template<typename T>
struct IsArrayT : std::false_type {       // primary template: not an array
};

template<typename T, std::size_t N>
struct IsArrayT<T[N]> : std::true_type {  // partial specialization for arrays
  using BaseT = T;
  static constexpr std::size_t size = N;
};

template<typename T>
struct IsArrayT<T[]> : std::true_type {  // partial specialization for unbound arrays
  using BaseT = T;
  static constexpr std::size_t size = 0;
};

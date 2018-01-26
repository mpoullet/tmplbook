template<typename T>
struct IsPointerT : std::false_type {    // primary template: by default not a pointer
};

template<typename T>
struct IsPointerT<T*> : std::true_type { // partial specialization for pointers
  using BaseT = T;  // type pointing to
};

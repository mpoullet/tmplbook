template<typename T>
struct RemoveVolatileT {
  using Type = T;
};

template<typename T>
struct RemoveVolatileT<volatile T> {
  using Type = T;
};

template<typename T>
using RemoveVolatile = typename RemoveVolatileT<T>::Type;

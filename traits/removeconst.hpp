template<typename T>
struct RemoveConstT {
  using Type = T;
};

template<typename T>
struct RemoveConstT<T const> {
  using Type = T;
};

template<typename T>
using RemoveConst = typename RemoveConstT<T>::Type;

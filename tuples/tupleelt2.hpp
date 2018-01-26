#include <type_traits>

template<unsigned Height, typename T,
         bool = std::is_class<T>::value && !std::is_final<T>::value>
class TupleElt;

template<unsigned Height, typename T>
class TupleElt<Height, T, false>
{
  T value;

 public:
  TupleElt() = default;
  template<typename U>
    TupleElt(U&& other) : value(std::forward<U>(other)) { }

  T&       get()       { return value; }
  T const& get() const { return value; }
};

template<unsigned Height, typename T>
class TupleElt<Height, T, true> : private T
{
 public:
  TupleElt() = default;
  template<typename U>
    TupleElt(U&& other) : T(std::forward<U>(other)) { }

  T&       get()       { return *this; }
  T const& get() const { return *this; }
};

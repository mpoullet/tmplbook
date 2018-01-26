// recursive case:
template<unsigned N>
struct TupleGet {
  template<typename Head, typename... Tail>
  static auto apply(Tuple<Head, Tail...> const& t) {
    return TupleGet<N-1>::apply(t.getTail());
  }
};

// basis case:
template<>
struct TupleGet<0> {
  template<typename Head, typename... Tail>
  static Head const& apply(Tuple<Head, Tail...> const& t) {
    return t.getHead();
  }
};

template<unsigned N, typename... Types>
auto get(Tuple<Types...> const& t) {
  return TupleGet<N>::apply(t);
}

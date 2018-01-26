template<typename... Types>
class Tuple;

// recursive case:
template<typename Head, typename... Tail>
class Tuple<Head, Tail...> 
 : private TupleElt<sizeof...(Tail), Head>, private Tuple<Tail...>
{
  using HeadElt = TupleElt<sizeof...(Tail), Head>;
 public:
  Head& getHead() { 
    return static_cast<HeadElt *>(this)->get();
  }
  Head const& getHead() const { 
    return static_cast<HeadElt const*>(this)->get();
  }
  Tuple<Tail...>& getTail() { return *this; }
  Tuple<Tail...> const& getTail() const { return *this; }
};

// basis case:
template<>
class Tuple<> {
  // no storage required
};

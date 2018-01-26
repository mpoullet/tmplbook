template<typename... Types>
class Tuple;

template<typename T>
class TupleElt
{
  T value;

 public:
  TupleElt() = default;

  template<typename U>
  TupleElt(U&& other) : value(std::forward<U>(other) { }

  T&       get()       { return value; }
  T const& get() const { return value; }
};

// recursive case:
template<typename Head, typename... Tail>
class Tuple<Head, Tail...> 
 : private TupleElt<Head>, private Tuple<Tail...>
{
 public:
  Head& getHead() { 
    // potentially ambiguous
    return static_cast<TupleElt<Head> *>(this)->get();
  }
  Head const& getHead() const { 
    // potentially ambiguous
    return static_cast<TupleElt<Head> const*>(this)->get();
  }
  Tuple<Tail...>& getTail() { return *this; }
  Tuple<Tail...> const& getTail() const { return *this; }
};

// basis case:
template<>
class Tuple<> {
  // no storage required
};

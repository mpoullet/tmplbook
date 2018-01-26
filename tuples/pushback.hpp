// basis case
template<typename V>
Tuple<V> pushBack(Tuple<> const&, V const& value)
{
  return Tuple<V>(value);
}

// recursive case
template<typename Head, typename... Tail, typename V>
Tuple<Head, Tail..., V>
pushBack(Tuple<Head, Tail...> const& tuple, V const& value) 
{
  return Tuple<Head, Tail..., V>(tuple.getHead(),
                                 pushBack(tuple.getTail(), value));
}

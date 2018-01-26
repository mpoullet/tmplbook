template<typename... Types, typename V>
PushFront<Tuple<Types...>, V> 
pushFront(Tuple<Types...> const& tuple, V const& value)
{
  return PushFront<Tuple<Types...>, V>(value, tuple);
}

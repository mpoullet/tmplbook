template<typename... Types>
PopFront<Tuple<Types...>> 
popFront(Tuple<Types...> const& tuple)
{
  return tuple.getTail();
}

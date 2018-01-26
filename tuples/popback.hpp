template<typename... Types>
PopBack<Tuple<Types...>> 
popBack(Tuple<Types...> const& tuple)
{
  return reverse(popFront(reverse(tuple)));
}

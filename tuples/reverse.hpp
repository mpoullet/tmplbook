// basis case
Tuple<> reverse(Tuple<> const& t)
{
  return t;
}

// recursive case
template<typename Head, typename... Tail>
Reverse<Tuple<Head, Tail...>> reverse(Tuple<Head, Tail...> const& t) 
{
  return pushBack(reverse(t.getTail()), t.getHead());
}

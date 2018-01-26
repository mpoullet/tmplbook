template<typename... Elements, unsigned... Indices>
auto reverseImpl(Tuple<Elements...> const& t, 
                 Valuelist<unsigned, Indices...>)
{
  return makeTuple(get<Indices>(t)...);
}

template<typename... Elements>
auto reverse(Tuple<Elements...> const& t) 
{
  return reverseImpl(t, 
                     Reverse<MakeIndexList<sizeof...(Elements)>>());
}

template<typename... Elements, unsigned... Indices>
auto select(Tuple<Elements...> const& t, 
            Valuelist<unsigned, Indices...>)
{
  return makeTuple(get<Indices>(t)...);
}

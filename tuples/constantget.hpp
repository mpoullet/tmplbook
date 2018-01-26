template<unsigned H, typename T>
T& getHeight(TupleElt<H,T>& te)
{
  return te.get();
}

template<typename... Types>
class Tuple;

template<unsigned I, typename... Elements>
auto get(Tuple<Elements...>& t) 
  -> decltype(getHeight<sizeof...(Elements)-I-1>(t))
{
  return getHeight<sizeof...(Elements)-I-1>(t);
}

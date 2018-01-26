template<typename... Types>
auto makeTuple(Types&&... elems)
{
  return Tuple<std::decay_t<Types>...>(std::forward<Types>(elems)...);
}

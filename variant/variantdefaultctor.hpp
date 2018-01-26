template<typename... Types>
Variant<Types...>::Variant() {
  *this = Front<Typelist<Types...>>();
}


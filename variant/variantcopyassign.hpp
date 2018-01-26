template<typename... Types>
Variant<Types...>& Variant<Types...>::operator= (Variant const& source) {
  if (!source.empty()) {
    source.visit([&](auto const& value) {
                   *this = value;
                 });
  }
  else {
    destroy();
  }
  return *this;
}


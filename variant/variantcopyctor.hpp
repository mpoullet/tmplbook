template<typename... Types>
Variant<Types...>::Variant(Variant const& source) {
  if (!source.empty()) {
    source.visit([&](auto const& value) {
                   *this = value;
                 });
  }
}

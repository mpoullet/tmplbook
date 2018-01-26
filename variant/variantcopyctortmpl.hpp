template<typename... Types>
 template<typename... SourceTypes>
Variant<Types...>::Variant(Variant<SourceTypes...> const& source) {
  if (!source.empty()) {
    source.visit([&](auto const& value) {
                   *this = value;
                 });
  }
}

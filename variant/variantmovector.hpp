template<typename... Types>
Variant<Types...>::Variant(Variant&& source) {
  if (!source.empty()) {
    std::move(source).visit([&](auto&& value) {
                              *this = std::move(value);
                            });
  }
}

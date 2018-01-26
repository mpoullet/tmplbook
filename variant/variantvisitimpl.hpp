template<typename R, typename V, typename Visitor,
         typename Head, typename... Tail>
R variantVisitImpl(V&& variant, Visitor&& vis, Typelist<Head, Tail...>) {
  if (variant.template is<Head>()) {
    return static_cast<R>(
             std::forward<Visitor>(vis)(
               std::forward<V>(variant).template get<Head>()));
  }
  else if constexpr (sizeof...(Tail) > 0) {
    return variantVisitImpl<R>(std::forward<V>(variant),
                               std::forward<Visitor>(vis),
                               Typelist<Tail...>());
  }
  else {
    throw EmptyVariant();
  }
}

template<typename... Types>
 template<typename R, typename Visitor>
VisitResult<R, Visitor, Types&...>
Variant<Types...>::visit(Visitor&& vis)& {
  using Result = VisitResult<R, Visitor, Types&...>;
  return variantVisitImpl<Result>(*this, std::forward<Visitor>(vis),
                                  Typelist<Types...>());
}

template<typename... Types>
 template<typename R, typename Visitor>
VisitResult<R, Visitor, Types const&...>
Variant<Types...>::visit(Visitor&& vis) const& {
  using Result = VisitResult<R, Visitor, Types const &...>;
  return variantVisitImpl<Result>(*this, std::forward<Visitor>(vis),
                                 Typelist<Types...>());
}

template<typename... Types>
 template<typename R, typename Visitor>
VisitResult<R, Visitor, Types&&...>
Variant<Types...>::visit(Visitor&& vis) && {
  using Result = VisitResult<R, Visitor, Types&&...>;
  return variantVisitImpl<Result>(std::move(*this),
                                  std::forward<Visitor>(vis),
                                  Typelist<Types...>());
}

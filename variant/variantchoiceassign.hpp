template<typename T, typename... Types>
auto VariantChoice<T, Types...>::operator= (T const& value) -> Derived& {
  if (getDerived().getDiscriminator() == Discriminator) {
    // assign new value of same type:
    *getDerived().template getBufferAs<T>() = value;
  }
  else {
    // assign new value of different type:
    getDerived().destroy();    // try destroy() for all types
    new(getDerived().getRawBuffer()) T(value);  // place new value
    getDerived().setDiscriminator(Discriminator);
  }
  return getDerived();
}

template<typename T, typename... Types>
auto VariantChoice<T, Types...>::operator= (T&& value) -> Derived& {
  if (getDerived().getDiscriminator() == Discriminator) {
    // assign new value of same type:
    *getDerived().template getBufferAs<T>() = std::move(value);
  }
  else {
    // assign new value of different type:
    getDerived().destroy();    // try destroy() for all types
    new(getDerived().getRawBuffer()) T(std::move(value));  // place new value
    getDerived().setDiscriminator(Discriminator);
  }
  return getDerived();
}

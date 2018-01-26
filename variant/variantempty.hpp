template<typename... Types>
bool Variant<Types...>::empty() const {
  return this->getDiscriminator() == 0;
}

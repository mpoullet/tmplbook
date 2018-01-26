template<typename... Types>
template<typename T>
bool Variant<Types...>::is() const
{ 
  return this->getDiscriminator() ==
           VariantChoice<T, Types...>::Discriminator;
}

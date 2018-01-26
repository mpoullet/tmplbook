template<typename... Types>
void Variant<Types...>::destroy()
{
  // call destroy() on each VariantChoice base class; at most one will succeed:
  (VariantChoice<Types, Types...>::destroy() , ...);

  // indicate that the variant does not store a value
  this->setDiscriminator(0);
}


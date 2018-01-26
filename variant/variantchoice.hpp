#include "findindexof.hpp"

template<typename T, typename... Types>
class VariantChoice {
  using Derived = Variant<Types...>;
  Derived& getDerived() { return *static_cast<Derived*>(this); }
  Derived const& getDerived() const {
    return *static_cast<Derived const*>(this);
  }
 protected:
  // compute the discriminator to be used for this type
  constexpr static unsigned Discriminator =
    FindIndexOfT<Typelist<Types...>, T>::value + 1;
 public:
  VariantChoice() { }
  VariantChoice(T const& value);          // see variantchoiceinit.hpp
  VariantChoice(T&& value);               // see variantchoiceinit.hpp
  bool destroy();                         // see variantchoicedestroy.hpp
  Derived& operator= (T const& value);    // see variantchoiceassign.hpp
  Derived& operator= (T&& value);         // see variantchoiceassign.hpp
};

template<typename... Types>
class Variant {
 public:
  Tuple<Types...> storage;
  unsigned char discriminator;
};

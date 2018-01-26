template<typename List>
class IsEmpty
{
 public:
  static constexpr bool value = false;
};

template<>
class IsEmpty<Typelist<>> {
 public:
  static constexpr bool value = true;
};

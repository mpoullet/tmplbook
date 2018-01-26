#include <type_traits>  // for true_type, false_type, and void_t

#define DEFINE_HAS_MEMBER(Member)                                   \
  template<typename, typename = std::void_t<>>                      \
  struct HasMemberT_##Member                                        \
   : std::false_type { };                                           \
  template<typename T>                                              \
  struct HasMemberT_##Member<T, std::void_t<decltype(&T::Member)>>  \
   : std::true_type { } // ; intentionally skipped

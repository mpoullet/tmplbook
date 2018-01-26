#include <type_traits>  // for true_type, false_type, and void_t

#define DEFINE_HAS_TYPE(MemType)                                   \
  template<typename, typename = std::void_t<>>                     \
  struct HasTypeT_##MemType                                        \
   : std::false_type { };                                          \
  template<typename T>                                             \
  struct HasTypeT_##MemType<T, std::void_t<typename T::MemType>>   \
   : std::true_type { } // ; intentionally skipped

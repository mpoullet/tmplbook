#include <utility>        // for declval()
#include <type_traits>    // for true_type and false_type

template<typename T>
class IsEqualityComparable
{
 private:
  // test convertibility of == and ! == to bool:
  static void* conv(bool);  // to check convertibility to bool
  template<typename U>
   static std::true_type test(decltype(conv(std::declval<U const&>() ==
                                            std::declval<U const&>())),
                              decltype(conv(!(std::declval<U const&>() ==
                                              std::declval<U const&>())))
                             );
  // fallback:
  template<typename U>
   static std::false_type test(...);
 public:
  static constexpr bool value = decltype(test<T>(nullptr,
                                                 nullptr))::value;
};

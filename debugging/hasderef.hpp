#include <utility>        // for declval()
#include <type_traits>    // for true_type and false_type

template<typename T>
class HasDereference {
 private:
  template<typename U> struct Identity;
  template<typename U> static std::true_type 
    test(Identity<decltype(*std::declval<U>())>*);
  template<typename U> static std::false_type
    test(...);
 public:
  static constexpr bool value = decltype(test<T>(nullptr))::value;
};

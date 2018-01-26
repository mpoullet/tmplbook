#include <type_traits>

template<typename T, typename = std::void_t<>>
struct IsClassT : std::false_type {      // primary template: by default no class
};

template<typename T>
struct IsClassT<T, std::void_t<int T::*>>  // classes can have pointer-to-member
 : std::true_type {
};

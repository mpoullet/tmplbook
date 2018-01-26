#include <type_traits>  // for bool_constant
#include <utility>      // for declval

template <typename T>
struct IsNothrowMoveConstructibleT
    : std::bool_constant<noexcept(T(std::declval<T>()))> {};

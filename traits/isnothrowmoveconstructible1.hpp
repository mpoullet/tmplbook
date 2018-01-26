#include <utility>      // for declval
#include <type_traits>  // for bool_constant

template<typename T>
struct IsNothrowMoveConstructibleT
 : std::bool_constant<noexcept(T(std::declval<T>()))>
{
};

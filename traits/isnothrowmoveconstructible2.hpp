#include <utility>      // for declval
#include <type_traits>  // for true_type, false_type, and bool_constant<>

// primary template:
template<typename T, typename = std::void_t<>>
struct IsNothrowMoveConstructibleT : std::false_type
{
};

// partial specialization (may be SFINAE'd away):
template<typename T>
struct IsNothrowMoveConstructibleT
          <T, std::void_t<decltype(T(std::declval<T>()))>>
 : std::bool_constant<noexcept(T(std::declval<T>()))>
{
};

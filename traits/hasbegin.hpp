#include <utility>      // for declval
#include <type_traits>  // for true_type, false_type, and void_t

// primary template:
template<typename, typename = std::void_t<>>
struct HasBeginT : std::false_type {
};

// partial specialization (may be SFINAE'd away):
template<typename T>
struct HasBeginT<T, std::void_t<decltype(std::declval<T>().begin())>>
 : std::true_type {
};

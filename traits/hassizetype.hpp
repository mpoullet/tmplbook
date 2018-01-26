#include <type_traits>  // defines true_type and false_type

// helper to ignore any number of template parameters: 
template<typename...> using VoidT = void;

// primary template:
template<typename, typename = VoidT<>>
struct HasSizeTypeT : std::false_type
{
};

// partial specialization (may be SFINAE'd away):
template<typename T>
struct HasSizeTypeT<T, VoidT<typename T::size_type>> : std::true_type
{
};

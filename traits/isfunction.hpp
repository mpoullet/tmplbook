#include "../typelist/typelist.hpp"

template<typename T>
struct IsFunctionT : std::false_type {        // primary template: no function
};

template<typename R, typename... Params>
struct IsFunctionT<R (Params...)> : std::true_type {      // functions
    using Type = R;
    using ParamsT = Typelist<Params...>;
    static constexpr bool variadic = false;
};

template<typename R, typename... Params>
struct IsFunctionT<R (Params..., ...)> : std::true_type { // variadic functions
    using Type = R;
    using ParamsT = Typelist<Params...>;
    static constexpr bool variadic = true;
};

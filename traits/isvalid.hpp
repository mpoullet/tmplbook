#include <utility>

// helper: checking validity of \T\TI{f}(\TI{args}...)} for F \TI{f} and Args... \TI{args:
template<typename F, typename... Args,
         typename = decltype(std::declval<F>()(std::declval<Args&&>()...))>
std::true_type isValidImpl(void*);

// fallback if helper SFINAE'd out:
template<typename F, typename... Args>
std::false_type isValidImpl(...);

// define a lambda that takes a lambda f and returns whether calling f with args is valid
inline constexpr
auto isValid = [](auto f) {
                 return [](auto&&... args) {
                          return decltype(isValidImpl<decltype(f),
                                                      decltype(args)&&...
                                                     >(nullptr)){};
                        };
               };

// helper template to represent a type as a value
template<typename T>
struct TypeT {
    using Type = T;
};

// helper to wrap a type as a value
template<typename T>
constexpr auto type = TypeT<T>{};

// helper to unwrap a wrapped type in unevaluated contexts
template<typename T>
T valueT(TypeT<T>);  // no definition needed

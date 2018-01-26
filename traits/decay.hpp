#include "removecv.hpp"

template<typename T>
struct DecayT : RemoveCVT<T> {
};

template<typename T>
struct DecayT<T[]> {
  using Type = T*;
};

template<typename T, std::size_t N>
struct DecayT<T[N]> {
  using Type = T*;
};

template<typename R, typename... Args>
struct DecayT<R(Args...)> {
  using Type = R (*)(Args...);
};

template<typename R, typename... Args>
struct DecayT<R(Args..., ...)> {
  using Type = R (*)(Args..., ...);
};

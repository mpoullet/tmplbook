#include <type_traits>

template<typename T>
struct IsDefaultConstructibleHelper {
  private:
    // test() trying substitute call of a default constructor for T passed as U:
    template<typename U, typename = decltype(U())>
      static std::true_type test(void*);
    // test() fallback:
    template<typename>
      static std::false_type test(...);
  public:
    using Type = decltype(test<T>(nullptr));
};

template<typename T>
struct IsDefaultConstructibleT : IsDefaultConstructibleHelper<T>::Type {
};

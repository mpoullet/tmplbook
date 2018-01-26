using std::declval;

template<typename T, typename U>
class CommonTypeT
{
 public:
  using Type = decltype(true? declval<T>() : declval<U>());
};

template<typename T, typename U>
using CommonType = typename CommonTypeT<T, U>::Type;

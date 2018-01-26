template<typename T, typename U>
auto addA(T t, U u) -> decltype(t+u)
{
  return t + u;
}

void addA(...);

template<typename T, typename U>
auto addB(T t, U u) -> decltype(auto)
{
  return t + u;
}

void addB(...);

struct X {
};

using AddResultA = decltype(addA(X(), X())); // OK: AddResultA is void
using AddResultB = decltype(addB(X(), X())); // ERROR: instantiation of addB<X>
                                             //      is ill-formed

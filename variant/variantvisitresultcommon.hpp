#include "accumulate.hpp"
#include "commontype.hpp"

// the result type produced when calling a visitor with a value of type T:
template<typename Visitor, typename T>
using VisitElementResult = decltype(declval<Visitor>()(declval<T>()));

// the common result type for a visitor called with each of the given element types:
template<typename Visitor, typename... ElementTypes>
class VisitResultT<ComputedResultType, Visitor, ElementTypes...>
{
  using ResultTypes =
    Typelist<VisitElementResult<Visitor, ElementTypes>...>;

 public:
  using Type =
    Accumulate<PopFront<ResultTypes>, CommonTypeT, Front<ResultTypes>>;
};

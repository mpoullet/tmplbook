// an explicitly-provided visitor result type:
template<typename R, typename Visitor, typename... ElementTypes>
class VisitResultT
{
 public:
  using Type = R;
};

template<typename R, typename Visitor, typename... ElementTypes>
using VisitResult =
typename VisitResultT<R, Visitor, ElementTypes...>::Type;

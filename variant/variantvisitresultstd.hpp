template<typename Visitor, typename... ElementTypes>
class VisitResultT<ComputedResultType, Visitor, ElementTypes...>
{
 public:
  using Type =
    std::common_type_t<VisitElementResult<Visitor, ElementTypes>...>;
};

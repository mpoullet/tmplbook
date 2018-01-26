template<typename... Elements, template<typename T> class MetaFun>
class TransformT<Typelist<Elements...>, MetaFun, false>
{
 public:
  using Type = Typelist<typename MetaFun<Elements>::Type...>;
};

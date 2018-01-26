template<bool val>
struct BoolConstant {
  using Type = BoolConstant<val>;
  static constexpr bool value = val;
};
using TrueType  = BoolConstant<true>;
using FalseType = BoolConstant<false>;

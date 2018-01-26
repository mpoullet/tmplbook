// implementation of adding two ratios:
template<typename R1, typename R2>
struct RatioAddImpl
{
 private:
  static constexpr unsigned den = R1::den * R2::den;
  static constexpr unsigned num = R1::num * R2::den + R2::num * R1::den;
 public:
  typedef Ratio<num, den> Type;
};

// using declaration for convenient usage:
template<typename R1, typename R2>
using RatioAdd = typename RatioAddImpl<R1, R2>::Type;

// adding two durations where unit type might differ:
template<typename T1, typename U1, typename T2, typename U2>
auto constexpr operator+(Duration<T1, U1> const& lhs,
                         Duration<T2, U2> const& rhs)
{
   // resulting type is a unit with 1 a nominator and
   // the resulting denominator of adding both unit type fractions 
   using VT = Ratio<1,RatioAdd<U1,U2>::den>;
   // resulting value is the sum of both values
   // converted to the resulting unit type:
   auto val = lhs.value() * VT::den / U1::den * U1::num + 
              rhs.value() * VT::den / U2::den * U2::num;
   return Duration<decltype(val), VT>(val);
}

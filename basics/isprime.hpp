template<unsigned p, unsigned d>   // p: number to check, d: current divisor
struct DoIsPrime {
  static constexpr bool value = (p%d != 0) && DoIsPrime<p,d-1>::value; 
}; 

template<unsigned p>               // end recursion if divisor is 2
struct DoIsPrime<p,2> {
  static constexpr bool value = (p%2 != 0);
}; 

template<unsigned p>               // primary template
struct IsPrime {
  // start recursion with divisor from  p/2:
  static constexpr bool value = DoIsPrime<p,p/2>::value;
}; 

// special cases (to avoid endless recursion with template instantiation):
template<>
struct IsPrime<0> { static constexpr bool value = false; }; 
template<>
struct IsPrime<1> { static constexpr bool value = false; }; 
template<>
struct IsPrime<2> { static constexpr bool value = true; }; 
template<>
struct IsPrime<3> { static constexpr bool value = true; }; 

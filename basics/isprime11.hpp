constexpr bool
doIsPrime (unsigned p, unsigned d)  // p: number to check, d: current divisor
{
  return d!=2 ? (p%d!=0) && doIsPrime(p,d-1) // check this and smaller divisors
              : (p%2!=0);                    // end recursion if divisor is 2
}

constexpr bool isPrime (unsigned p)
{
  return p < 4 ? !(p<2)             // handle special cases
               : doIsPrime(p,p/2);  // start recursion with divisor from p/2
}

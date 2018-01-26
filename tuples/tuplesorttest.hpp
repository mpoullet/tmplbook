#include <complex>

template<typename T, typename U>
class SmallerThanT
{
 public:
  static constexpr bool value = sizeof(T) < sizeof(U);
};

void testTupleSort()
{
  auto t1 = makeTuple(17LL, std::complex<double>(42,77), 'c', 42, 7.7);
  std::cout << t1 << '\n';
  auto t2 = sort<SmallerThanT>(t1); // t2 is Tuple<int,~long,~std::string>
  std::cout << "sorted by size: " << t2 << '\n';
}

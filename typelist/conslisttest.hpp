template<typename T, typename U>
struct SmallerThanT {
  static constexpr bool value = sizeof(T) < sizeof(U);
};

void conslisttest()
{
  using ConsList = Cons<int, Cons<char, Cons<short, Cons<double>>>>;
  using SortedTypes = InsertionSort<ConsList, SmallerThanT>;
  using Expected = Cons<char, Cons<short, Cons<int, Cons<double>>>>;
  std::cout << std::is_same<SortedTypes, Expected>::value << '\n';
}

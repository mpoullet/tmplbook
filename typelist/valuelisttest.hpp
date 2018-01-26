template<typename T, typename U>
struct GreaterThanT;

template<typename T, T First, T Second>
struct GreaterThanT<CTValue<T, First>, CTValue<T, Second>> {
  static constexpr bool value = First > Second;
};

void valuelisttest()
{
  using Integers = Valuelist<int, 6, 2, 4, 9, 5, 2, 1, 7>;

  using SortedIntegers = InsertionSort<Integers, GreaterThanT>;

  static_assert(std::is_same_v<SortedIntegers, 
                               Valuelist<int, 9, 7, 6, 5, 4, 2, 2, 1>>,
                "insertion sort failed");
}

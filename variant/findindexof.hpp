template<typename List, typename T, unsigned N = 0, 
         bool Empty = IsEmpty<List>::value>
struct FindIndexOfT;

// recursive case:
template<typename List, typename T, unsigned N>
struct FindIndexOfT<List, T, N, false> 
 : public IfThenElse<std::is_same<Front<List>, T>::value,
                     std::integral_constant<unsigned, N>,
                     FindIndexOfT<PopFront<List>, T, N+1>>
{
};

// basis case:
template<typename List, typename T, unsigned N>
struct FindIndexOfT<List, T, N, true>
{
};

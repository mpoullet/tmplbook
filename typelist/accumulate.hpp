template<typename List,
         template<typename X, typename Y> class F,
         typename I, 
         bool = IsEmpty<List>::value>
class AccumulateT;

// recursive case:
template<typename List, 
         template<typename X, typename Y> class F,
         typename I>
class AccumulateT<List, F, I, false>
 : public AccumulateT<PopFront<List>, F, 
                      typename F<I, Front<List>>::Type>
{
};

// basis case:
template<typename List, 
         template<typename X, typename Y> class F,
         typename I>
class AccumulateT<List, F, I, true>
{
 public:
  using Type = I;
};

template<typename List, 
         template<typename X, typename Y> class F,
         typename I>
using Accumulate = typename AccumulateT<List, F, I>::Type;

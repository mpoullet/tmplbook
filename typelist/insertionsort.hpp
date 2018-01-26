template<typename List, 
         template<typename T, typename U> class Compare,
         bool = IsEmpty<List>::value>
class InsertionSortT;

template<typename List, 
         template<typename T, typename U> class Compare>
using InsertionSort = typename InsertionSortT<List, Compare>::Type;

// recursive case (insert first element into sorted list):
template<typename List,
         template<typename T, typename U> class Compare>
class InsertionSortT<List, Compare, false>
 : public InsertSortedT<InsertionSort<PopFront<List>, Compare>,
                        Front<List>, Compare>
{
};

// basis case (an empty list is sorted):
template<typename List,
         template<typename T, typename U> class Compare>
class InsertionSortT<List, Compare, true>
{
 public:
  using Type = List;
};

#include "identity.hpp"

template<typename List, typename Element,
         template<typename T, typename U> class Compare,
         bool = IsEmpty<List>::value>
class InsertSortedT;

// recursive case:
template<typename List, typename Element,
         template<typename T, typename U> class Compare>
class InsertSortedT<List, Element, Compare, false>
{
  // compute the tail of the resulting list:
  using NewTail =
    typename IfThenElse<Compare<Element, Front<List>>::value,
                        IdentityT<List>,
                        InsertSortedT<PopFront<List>, Element, Compare>
             >::Type;
  // compute the head of the resulting list:
  using NewHead = IfThenElse<Compare<Element, Front<List>>::value,
                             Element,
                             Front<List>>;
 public:
  using Type = PushFront<NewTail, NewHead>;
};

// basis case:
template<typename List, typename Element,
         template<typename T, typename U> class Compare>
class InsertSortedT<List, Element, Compare, true>
 : public PushFrontT<List, Element>
{
};

template<typename List, typename Element,
         template<typename T, typename U> class Compare>
using InsertSorted = typename InsertSortedT<List, Element, Compare>::Type;

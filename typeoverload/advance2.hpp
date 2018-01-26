#include <iterator>

// implementation for random access iterators:
template<typename Iterator, typename Distance>
EnableIf<IsRandomAccessIterator<Iterator>>
advanceIter(Iterator& x, Distance n) {
  x += n;  // constant time
}

template<typename Iterator>
constexpr bool IsBidirectionalIterator =
   IsConvertible<
     typename std::iterator_traits<Iterator>::iterator_category,
     std::bidirectional_iterator_tag>;

// implementation for bidirectional iterators:
template<typename Iterator, typename Distance>
EnableIf<IsBidirectionalIterator<Iterator> &&
         !IsRandomAccessIterator<Iterator>>
advanceIter(Iterator& x, Distance n) {
  if (n > 0) {
    for ( ; n > 0; ++x, --n) {  // linear time
    }
  } else {
    for ( ; n < 0; --x, ++n) {  // linear time
    }
  }
}

// implementation for all other iterators:
template<typename Iterator, typename Distance>
EnableIf<!IsBidirectionalIterator<Iterator>>
advanceIter(Iterator& x, Distance n) {
  if (n < 0) {
    throw "advanceIter(): invalid iterator category for negative n";
  }
  while (n > 0) {  // linear time
    ++x;
    --n;
  }
}

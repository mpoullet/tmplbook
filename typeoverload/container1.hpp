#include <iterator>
#include "enableif.hpp"
#include "isconvertible.hpp"

template<typename Iterator>
  constexpr bool IsInputIterator =
    IsConvertible<
      typename std::iterator_traits<Iterator>::iterator_category,   
      std::input_iterator_tag>;

template<typename T>
class Container {
 public:
  // construct from an input iterator sequence:
  template<typename Iterator, 
           typename = EnableIf<IsInputIterator<Iterator>>>
  Container(Iterator first, Iterator last);

  // convert to a container so long as the value types are convertible:
  template<typename U, typename = EnableIf<IsConvertible<T, U>>>
  operator Container<U>() const;
};

template<typename T>
class Container {
 public:
  // construct from an input iterator sequence:
  template<typename Iterator>
  requires IsInputIterator<Iterator>
  Container(Iterator first, Iterator last);

  // construct from a random access iterator sequence:
  template<typename Iterator>
  requires IsRandomAccessIterator<Iterator>
  Container(Iterator first, Iterator last);

  // convert to a container so long as the value types are convertible:
  template<typename U>
  requires IsConvertible<T, U>
  operator Container<U>() const;
};

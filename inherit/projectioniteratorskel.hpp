template<typename Iterator, typename T>
class ProjectionIterator
 : public IteratorFacade<
            ProjectionIterator<Iterator, T>,
            T,
            typename std::iterator_traits<Iterator>::iterator_category,
            T&,
            typename std::iterator_traits<Iterator>::difference_type>
{
  using Base = typename std::iterator_traits<Iterator>::value_type;
  using Distance =
    typename std::iterator_traits<Iterator>::difference_type;

  Iterator iter;
  T Base::* member;

  friend class IteratorFacadeAccess;
  //... // implement core iterator operations for IteratorFacade
 public:
  ProjectionIterator(Iterator iter, T Base::* member)
    : iter(iter), member(member) { }
};

template<typename Iterator, typename Base, typename T>
auto project(Iterator iter, T Base::* member) {
  return ProjectionIterator<Iterator, T>(iter, member);
}

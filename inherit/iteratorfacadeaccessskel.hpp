// `friend' this class to allow IteratorFacade access to core iterator operations:
class IteratorFacadeAccess
{
  // only IteratorFacade can use these definitions
  template<typename Derived, typename Value, typename Category,
           typename Reference, typename Distance>
    friend class IteratorFacade;

  // required of all iterators:
  template<typename Reference, typename Iterator>
  static Reference dereference(Iterator const& i) {
    return i.dereference();
  }
  //...
  // required of bidirectional iterators:
  template<typename Iterator>
  static void decrement(Iterator& i) {
    return i.decrement();
  }

  // required of random-access iterators:
  template<typename Iterator, typename Distance>
  static void advance(Iterator& i, Distance n) {
    return i.advance(n);
  }
  //...
};

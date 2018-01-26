template<typename Derived, typename Value, typename Category,
         typename Reference = Value&, typename Distance = std::ptrdiff_t>
class IteratorFacade
{
 public:
  using value_type = typename std::remove_const<Value>::type;
  using reference = Reference;
  using pointer = Value*;
  using difference_type = Distance;
  using iterator_category = Category;

  // input iterator interface:
  reference operator *() const { //... }
  pointer operator ->() const { //... }
  Derived& operator ++() { //... }
  Derived operator ++(int) { //... }
  friend bool operator== (IteratorFacade const& lhs,
                          IteratorFacade const& rhs) { //... }
  //...
  // bidirectional iterator interface:
  Derived& operator --() { //... }
  Derived operator --(int) { //... }

  // random access iterator interface:
  reference operator [](difference_type n) const { //... }
  Derived& operator +=(difference_type n) { //... }
  //...
  friend difference_type operator -(IteratorFacade const& lhs,
                                    IteratorFacade const& rhs) { //... }
  friend bool operator <(IteratorFacade const& lhs,
                         IteratorFacade const& rhs) { //... }
  //...
};

template<typename T>
class ListNodeIterator
 : public IteratorFacade<ListNodeIterator<T>, T,
                         std::forward_iterator_tag>
{
  ListNode<T>* current = nullptr;
 public: 
  T& dereference() const {
    return current->value;
  }
  void increment() {
    current = current->next;
  }
  bool equals(ListNodeIterator const& other) const {
    return current == other.current;
  }
  ListNodeIterator(ListNode<T>* current = nullptr) : current(current) { }
};

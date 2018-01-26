template<typename T>
class ListNode
{
 public:
  T value;
  ListNode<T>* next = nullptr;
  ~ListNode() { delete next; }
};

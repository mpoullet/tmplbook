template<typename T, typename Cont>
class Stack;

template<typename T>
using DequeStack = Stack<T, std::deque<T>>;

template<typename T, typename Cont>
void f1(Stack<T, Cont>);

template<typename T>
void f2(DequeStack<T>);

template<typename T>
void f3(Stack<T, std::deque<T>);  // equivalent to f2

void test(DequeStack<int> intStack)
{
  f1(intStack);   // OK: T deduced to int, Cont deduced to std::deque<int>
  f2(intStack);   // OK: T deduced to int
  f3(intStack);   // OK: T deduced to int
}

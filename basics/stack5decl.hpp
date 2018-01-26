template <typename T>
class Stack {
  private:
    std::deque<T> elems;       // elements

  public:
    void push(T const&);       // push element
    void pop();                // pop element
    T const& top() const;      // return top element
    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }

    // assign stack of elements of type T2
    template <typename T2>
    Stack& operator= (Stack<T2> const&);
};

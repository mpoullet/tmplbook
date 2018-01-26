template<typename T,
         template<typename Elem> class Cont = std::deque>
class Stack {
  private:
    Cont<T> elems;             // elements

  public:
    void push(T const&);       // push element
    void pop();                // pop element
    T const& top() const;      // return top element
    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }
    //...
};

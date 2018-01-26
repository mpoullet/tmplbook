#include <deque>
#include <cassert>
#include <memory>

template<typename T,
         template<typename Elem,
                  typename = std::allocator<Elem>>
          class Cont = std::deque>
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

    // assign stack of elements of type T2
    template<typename T2,
             template<typename Elem2,
                      typename = std::allocator<Elem2>
                     >class Cont2>
    Stack<T,Cont>& operator= (Stack<T2,Cont2> const&);
    // to get access to private members of any Stack with elements of type T2:
    template<typename, template<typename, typename>class>
    friend class Stack;
};

template<typename T, template<typename,typename> class Cont>
void Stack<T,Cont>::push (T const& elem)
{
    elems.push_back(elem);    // append copy of passed elem
}

template<typename T, template<typename,typename> class Cont>
void Stack<T,Cont>::pop ()
{
    assert(!elems.empty());
    elems.pop_back();          // remove last element
}

template<typename T, template<typename,typename> class Cont>
T const& Stack<T,Cont>::top () const
{
    assert(!elems.empty());
    return elems.back();       // return copy of last element
}

template<typename T, template<typename,typename> class Cont>
 template<typename T2, template<typename,typename> class Cont2>
Stack<T,Cont>&
Stack<T,Cont>::operator= (Stack<T2,Cont2> const& op2)
{
    elems.clear();                        // remove existing elements
    elems.insert(elems.begin(),           // insert at the beginning
                 op2.elems.begin(),       // all elements from op2
                 op2.elems.end());
    return *this;
}

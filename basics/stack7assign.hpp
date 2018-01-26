template<typename T, typename Cont>
 template<typename T2, typename Cont2>
Stack<T,Cont>&
Stack<T,Cont>::operator= (Stack<T2,Cont2> const& op2)
{
    elems.clear();                        // remove existing elements
    elems.insert(elems.begin(),           // insert at the beginning
                 op2.elems.begin(),       // all elements from op2
                 op2.elems.end());
    return *this;
}

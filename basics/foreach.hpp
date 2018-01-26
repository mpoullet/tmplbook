template<typename Iter, typename Callable>
void foreach (Iter current, Iter end, Callable op)
{
  while (current != end) {  // as long as not reached the end
    op(*current);           //  call passed operator for current element
    ++current;              //  and move iterator to next element
  }
}

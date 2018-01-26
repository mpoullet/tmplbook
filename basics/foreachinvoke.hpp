#include <utility>
#include <functional>

template<typename Iter, typename Callable, typename... Args>
void foreach (Iter current, Iter end, Callable op, Args const&... args)
{
  while (current != end) {     // as long as not reached the end of the elements
    std::invoke(op,            // call passed callable with
                args...,       // any additional args
                *current);     // and the current element
    ++current;
  }
}

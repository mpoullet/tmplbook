#include <utility>     // for std::invoke()
#include <functional>  // for std::forward()

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& op, Args&&... args)
{
  return std::invoke(std::forward<Callable>(op),    // passed callable with
                     std::forward<Args>(args)...);  // any additional args
}

#include "variant-all.hpp"
#include <iostream>

template<typename V, typename Head, typename... Tail>
void printImpl(V const& v)
{
  if (v.template is<Head>()) {
    std::cout << v.template get<Head>();
  }
  else if constexpr (sizeof...(Tail) > 0) {
    printImpl<V, Tail...>(v);
  }
}

template<typename... Types>
void print(Variant<Types...> const& v)
{
  printImpl<Variant<Types...>, Types...>(v);
}

int main() {
  Variant<int, short, float, double> v(1.5);
  print(v);
}


#include <iostream>

template<typename T>
void tmplParamIsReference(T) {
  std::cout << "T is reference: " << std::is_reference_v<T> << '\n';
}

int main()
{
  std::cout << std::boolalpha;
  int i;
  int& r = i;
  tmplParamIsReference(i);         // false
  tmplParamIsReference(r);         // false
  tmplParamIsReference<int&>(i);   // true
  tmplParamIsReference<int&>(r);   // true
}

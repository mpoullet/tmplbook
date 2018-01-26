#include "hasmember.hpp"

#include <iostream>
#include <vector>
#include <utility>

DEFINE_HAS_MEMBER(size);
DEFINE_HAS_MEMBER(first);

int main()
{
  std::cout << "int::size: "
            << HasMemberT_size<int>::value << '\n';
  std::cout << "std::vector<int>::size: "
            << HasMemberT_size<std::vector<int>>::value << '\n';
  std::cout << "std::pair<int,int>::first: "
            << HasMemberT_first<std::pair<int,int>>::value << '\n';
}

#include <iostream>
#include "funcoverload1.hpp"

int main() 
{
    std::cout << f<int*>((int*)nullptr);  // calls f<T>(T)
    std::cout << f<int>((int*)nullptr);   // calls f<T>(T*)
}

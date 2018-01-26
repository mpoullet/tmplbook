#include <iostream>

template<typename T> 
int f(T)
{ 
    return 1;
}

template<typename T> 
int f(T*)
{ 
    return 2;
}

int main() 
{
    std::cout << f(0);              // calls f<T>(T)
    std::cout << f(nullptr);        // calls f<T>(T)
    std::cout << f((int*)nullptr);  // calls f<T>(T*)
}

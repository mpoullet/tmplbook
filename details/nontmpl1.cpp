#include <string>
#include <iostream>

template<typename T> 
std::string f(T) 
{ 
    return "Template"; 
}

std::string f(int&) 
{ 
    return "Nontemplate"; 
}

int main() 
{
    int x = 7;
    std::cout << f(x) << '\n';  // prints: Nontemplate
}

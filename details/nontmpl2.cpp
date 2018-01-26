#include <string>
#include <iostream>

template<typename T> 
std::string f(T&) 
{ 
    return "Template"; 
}

std::string f(int const&) 
{ 
    return "Nontemplate"; 
}

int main() 
{
    int x = 7;
    std::cout << f(x) << '\n';  // prints: Template
    int const c = 7;
    std::cout << f(c) << '\n';  // prints: Nontemplate
}

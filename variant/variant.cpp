#include "variant-all.hpp"
#include <iostream>
#include <string>

int main() 
{
  Variant<int, double, std::string> field(17);
  if (field.is<int>()) {
    std::cout << "Field stores the integer " << field.get<int>()
              << std::endl;
  }
  field = 42;      // assign value of same type
  field = "hello"; // assign value of different type
  std::cout << "Field now stores the string \"" 
            << field.get<std::string>() << '\"' << std::endl;
}

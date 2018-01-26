#include <iostream>

template<auto T>       // take value of any possible nontype parameter (since C++17)
class Message {
  public:
    void print() {
      std::cout << T << '\n'; 
    }
};

int main()
{
  Message<42> msg1;
  msg1.print();        // initialize with int 42 and print that value

  static char const s[] = "hello";
  Message<s> msg2;     // initialize with char~const[6] "hello"
  msg2.print();        // and print that value
}

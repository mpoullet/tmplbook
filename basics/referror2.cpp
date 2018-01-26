#include <vector>
#include <iostream>

template<typename T, int& SZ>     // Note: size is reference
class Arr {
  private:
    std::vector<T> elems;
  public:
    Arr() : elems(SZ) {           // use current SZ as initial vector size
    }
    void print() const {
      for (int i=0; i<SZ; ++i) {  // loop over SZ elements
        std::cout << elems[i] << ' ';  
      }
    }
};

int size = 10;

int main()
{
  Arr<int&,size> y; // compile-time ERROR deep in the code of class std::vector<>

  Arr<int,size> x;  // initializes internal vector with 10 elements
  x.print();        // OK
  size += 100;      // OOPS: modifies SZ in Arr<>
  x.print();        // run-time ERROR: invalid memory access: loops over 120 elements
}

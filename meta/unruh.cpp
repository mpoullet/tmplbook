// prime number computation 
// (modified from original from 1994 by Erwin Unruh)

template<int p, int i>
struct is_prime {
  enum { pri = (p==2) || ((p%i) && is_prime<(i>2?p:0),i-1>::pri) }; 
}; 

template<>
struct is_prime<0,0> {
  enum {pri=1};
}; 

template<>
struct is_prime<0,1> {
  enum {pri=1};
}; 

template<int i>
struct D {
  D(void*);
}; 

template<int i>
struct CondNull {
  static int const value = i;
};
template<>
struct CondNull<0> {
  static void* value;
};
void* CondNull<0>::value = 0;

template<int i>
struct Prime_print {      // primary template for loop to print prime numbers
  Prime_print<i-1> a; 
  enum { pri = is_prime<i,i-1>::pri }; 
  void f() {
    D<i> d = CondNull<pri ? 1 : 0>::value;  // 1 is an error, 0 is fine
    a.f();
  } 
}; 

template<>
struct Prime_print<1> {   // full specialization to end the loop
  enum {pri=0}; 
  void f() {
    D<1> d = 0;
  }; 
}; 

#ifndef LAST 
#define LAST 18 
#endif 

int main()
{
    Prime_print<LAST> a; 
    a.f(); 
} 

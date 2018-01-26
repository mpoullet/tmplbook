#include <iostream>

class C {
  public:
    C() {  // default constructor has no noexcept
    }
    virtual ~C() = default; // makes C nontrivial
};

int main()
{
  using namespace std;
  cout << is_default_constructible_v<C> << '\n';            // true
  cout << is_trivially_default_constructible_v<C> << '\n';  // false
  cout << is_nothrow_default_constructible_v<C> << '\n';    // false
  cout << is_copy_constructible_v<C> << '\n';               // true 
  cout << is_trivially_copy_constructible_v<C> << '\n';     // true
  cout << is_nothrow_copy_constructible_v<C> << '\n';       // true 
  cout << is_destructible_v<C> << '\n';                     // true 
  cout << is_trivially_destructible_v<C> << '\n';           // false
  cout << is_nothrow_destructible_v<C> << '\n';             // true
}

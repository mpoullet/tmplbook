template<int N>
class X {
  public:
    using I = int;
    void f(int) {
    }
};

template<int N> 
void fppm(void (X<N>::*p)(typename X<N>::I));

int main() 
{
    fppm(&X<33>::f);  // fine: N deduced to be 33
}

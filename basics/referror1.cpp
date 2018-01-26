template<typename T, T Z = T{}>
class RefMem {
  private:
    T zero;
  public:
    RefMem() : zero{Z} { 
    }
};

int null = 0;

int main()
{
    RefMem<int> rm1, rm2;
    rm1 = rm2;             // OK

    RefMem<int&> rm3;      // ERROR: invalid default value for N
    RefMem<int&, 0> rm4;   // ERROR: invalid default value for N

    extern int null;
    RefMem<int&,null> rm5, rm6;
    rm5 = rm6;             // ERROR: operator= is deleted due to reference member
}

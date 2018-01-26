template<typename T>
class AddSpace
{
  private:
    T const& ref;                  // refer to argument passed in constructor
  public:
    AddSpace(T const& r): ref(r) {
    }
    friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) {
      return os << s.ref << ' ';   // output passed argument and a space
    }
};

template<typename... Args>
void print (Args... args) {
  ( std::cout << ... << AddSpace(args) ) << '\n';
}

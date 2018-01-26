class MyClass {
  private:
    int value;
  public:
    friend bool operator < (MyClass const& x, MyClass const& y) {
        return x.value < y.value;
    }
    friend std::ostream& operator << (std::ostream& strm, MyClass const& x) {
        strm << x.value;
        return strm;
    }
};


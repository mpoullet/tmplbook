template<typename T, typename A1, typename A2>
class A_Subscript {
  public:
    // constructor initializes references to operands
    A_Subscript (A1 const& a, A2 const& b)
     : a1(a), a2(b) {
    }

    // process subscription when value requested
    decltype(auto) operator[] (std::size_t idx) const {
        return a1[a2[idx]];
    }
    T& operator[] (std::size_t idx) {
        return a1[a2[idx]];
    }

    // size is size of inner array
    std::size_t size() const {
        return a2.size();
    }
  private:
    A1 const& a1;    // reference to first operand
    A2 const& a2;    // reference to second operand
};

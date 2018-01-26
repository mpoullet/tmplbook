template<int N>
struct CopyCounter
{
  inline static unsigned numCopies = 0;
  CopyCounter() {
  }
  CopyCounter(CopyCounter const&) {
    ++numCopies;
  }
};

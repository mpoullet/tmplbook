#include <cstddef>
#include <cassert>

template<typename T>
class SArray {
  public:
    // create array with initial size
    explicit SArray (std::size_t s)
     : storage(new T[s]), storage_size(s) {
        init();
    }

    // copy constructor
    SArray (SArray<T> const& orig)
     : storage(new T[orig.size()]), storage_size(orig.size()) {
        copy(orig);
    }

    // destructor: free memory
    ~SArray() {
        delete[] storage;
    }

    // assignment operator
    SArray<T>& operator= (SArray<T> const& orig) {
        if (&orig!=this) {
            copy(orig);
        }
        return *this;
    }

    // return size
    std::size_t size() const {
        return storage_size;
    }

    // index operator for constants and variables
    T operator[] (std::size_t idx) const {
        return storage[idx];
    }
    T& operator[] (std::size_t idx) {
        return storage[idx];
    }

  protected:
    // init values with default constructor
    void init() {
        for (std::size_t idx = 0; idx<size(); ++idx) {
            storage[idx] = T();
        }
    }
    // copy values of another array
    void copy (SArray<T> const& orig) {
        assert(size()==orig.size());
        for (std::size_t idx = 0; idx<size(); ++idx) {
            storage[idx] = orig.storage[idx];
        }
    }

  private:
    T*          storage;       // storage of the elements
    std::size_t storage_size;  // number of elements

  public:
    SArray<T>& operator+= (SArray<T> const& b);
    SArray<T>& operator*= (SArray<T> const& b);
    SArray<T>& operator*= (T const& s);
};

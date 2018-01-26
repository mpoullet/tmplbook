#include <cstddef>

template<typename CountedType>
class ObjectCounter {
  private:
    inline static std::size_t count = 0;    // number of existing objects

  protected:
    // default constructor
    ObjectCounter() { 
        ++count;
    }

    // copy constructor
    ObjectCounter (ObjectCounter<CountedType> const&) {
        ++count; 
    }

    // move constructor
    ObjectCounter (ObjectCounter<CountedType> &&) {
        ++count; 
    }

    // destructor
    ~ObjectCounter() { 
        --count;
    }

  public:
    // return number of existing objects:
    static std::size_t live() { 
        return count; 
    }
};

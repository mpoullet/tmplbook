#include <new>  // for std::launder()

template<typename... Types>
class VariantStorage {
  using LargestT = LargestType<Typelist<Types...>>;
  alignas(Types...) unsigned char buffer[sizeof(LargestT)];
  unsigned char discriminator = 0;
 public:
  unsigned char getDiscriminator() const { return discriminator; }
  void setDiscriminator(unsigned char d) { discriminator = d; }

  void* getRawBuffer() { return buffer; }
  const void* getRawBuffer() const { return buffer; }

  template<typename T>
    T* getBufferAs() { return std::launder(reinterpret_cast<T*>(buffer)); }
  template<typename T>
    T const* getBufferAs() const {
      return std::launder(reinterpret_cast<T const*>(buffer));
    }
};

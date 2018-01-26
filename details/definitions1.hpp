template<typename T>            // a namespace scope class template
class Data {
  public:
    static constexpr bool copyable = true;
    //...
};

template<typename T>            // a namespace scope function template
void log (T x) {
    //...
}

template<typename T>            // a namespace scope variable template (since C++14)
T zero = 0;

template<typename T>            // a namespace scope variable template (since C++14)
bool dataCopyable = Data<T>::copyable;

template<typename T>            // a namespace scope alias template
using DataList = Data<T*>;

class Collection {
  public:
    template<typename T>        // an in-class member class template definition
    class Node {
        //...
    };

    template<typename T>        // an in-class (and therefore implicitly inline)
    T* alloc() {                // member function template definition
        //...
    }

    template<typename T>        // a member variable template (since C++14)
     static T zero = 0;

    template<typename T>        // a member alias template
     using NodePtr = Node<T>*;
};

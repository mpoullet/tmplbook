template<typename T>            // a namespace scope class template
class List {
  public:
    List() = default;           // because a template constructor is defined

    template<typename U>        // another member class template,
     class Handle;              //  without its definition

    template<typename U>        // a member function template
     List (List<U> const&);     //  (constructor)

    template<typename U>        // a member variable template (since C++14)
     static U zero;
};

template<typename T>            // out-of-class member class template definition
 template<typename U>
class List<T>::Handle {
    //...
};

template<typename T>            // out-of-class member function template definition
 template<typename T2>
List<T>::List (List<T2> const& b)
{
    //...
}

template<typename T>            // out-of-class static data member template definition
 template<typename U>
U List<T>::zero = 0;

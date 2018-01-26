template<typename T> 
class Safe {
};

template<int N>
class Danger {
    int arr[N];                   // OK here, although would fail for N<=0 
};

template<typename T, int N>
class Tricky {
  public:
    void noBodyHere(Safe<T> = 3); // OK until \IBusage of default value results in an error
    void inclass() { 
        Danger<N> noBoomYet;      // OK until inclass() is \IBused with N<=0
    }
    struct Nested { 
        Danger<N> pfew;           // OK until Nested is \IBused with N<=0
    };
    union {                       // due anonymous union:
        Danger<N> anonymous;      // OK until Tricky is \IBinstantiated with N<=0
        int align;
    };
    void unsafe(T (*p)[N]);       // OK until Tricky is \IBinstantiated with N<=0
    void error() {
        Danger<-1> boom;          // \IBalways ERROR (which not all compilers detect)
    }
};

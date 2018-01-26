template<typename T>
struct IsRValueReferenceT : std::false_type {     // by default no rvalue reference
};

template<typename T>
struct IsRValueReferenceT<T&&> : std::true_type { // unless T is rvalue reference
    using BaseT = T;  // type referring to
};

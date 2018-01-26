template<typename T>
struct IsLValueReferenceT : std::false_type {     // by default no lvalue reference
};

template<typename T>
struct IsLValueReferenceT<T&> : std::true_type {  // unless T is lvalue references
    using BaseT = T;  // type referring to
};

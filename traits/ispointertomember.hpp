template<typename T>
struct IsPointerToMemberT : std::false_type {   // by default no pointer-to-member
};

template<typename T, typename C>
struct IsPointerToMemberT<T C::*> : std::true_type {  // partial specialization
    using MemberT = T;
    using ClassT = C;
};

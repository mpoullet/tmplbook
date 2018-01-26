template<typename T>
struct IsEnumT {
    static constexpr bool value = !IsFundaT<T>::value &&
                                  !IsPointerT<T>::value &&
                                  !IsReferenceT<T>::value &&
                                  !IsArrayT<T>::value &&
                                  !IsPointerToMemberT<T>::value &&
                                  !IsFunctionT<T>::value &&
                                  !IsClassT<T>::value;
};

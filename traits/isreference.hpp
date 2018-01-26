#include "ifthenelse.hpp"
#include "islvaluereference.hpp"
#include "isrvaluereference.hpp"

template <typename T>
class IsReferenceT
    : public IfThenElseT<IsLValueReferenceT<T>::value, IsLValueReferenceT<T>,
                         IsRValueReferenceT<T> >::Type {};

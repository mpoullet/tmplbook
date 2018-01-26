#ifndef IFTHENELSE_HPP
#define IFTHENELSE_HPP

// primary template: yield second or third argument depending on first argument
template<bool COND, typename TrueType, typename FalseType>
struct IfThenElseT;

// partial specialization: true yields second argument
template<typename TrueType, typename FalseType>
struct IfThenElseT<true, TrueType, FalseType> {
    using Type = TrueType;
};

// partial specialization: false yields third argument
template<typename TrueType, typename FalseType>
struct IfThenElseT<false, TrueType, FalseType> {
    using Type = FalseType;
};

#endif // IFTHENELSE_HPP

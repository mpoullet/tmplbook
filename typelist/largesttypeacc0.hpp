template<typename T, typename U>
class LargerTypeT 
 : public IfThenElseT<sizeof(T) >= sizeof(U), T, U>
{
};

template<typename Typelist>
class LargestTypeAccT
 : public AccumulateT<PopFront<Typelist>, LargerTypeT, 
                      Front<Typelist>>
{
};

template<typename Typelist>
using LargestTypeAcc = typename LargestTypeAccT<Typelist>::Type;

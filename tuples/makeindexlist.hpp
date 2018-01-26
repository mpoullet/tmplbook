// recursive case
template<unsigned N, typename Result = Valuelist<unsigned>>
struct MakeIndexListT
 : MakeIndexListT<N-1, PushFront<Result, CTValue<unsigned, N-1>>>
{
};

// basis case
template<typename Result>
struct MakeIndexListT<0, Result>
{
  using Type = Result;
};

template<unsigned N>
using MakeIndexList = typename MakeIndexListT<N>::Type;

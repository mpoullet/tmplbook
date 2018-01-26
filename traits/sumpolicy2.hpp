#ifndef SUMPOLICY_HPP
#define SUMPOLICY_HPP

template<typename T1, typename T2>
class SumPolicy {
  public:
    static void accumulate (T1& total, T2 const& value) {
        total += value;
    }
};

#endif // SUMPOLICY_HPP

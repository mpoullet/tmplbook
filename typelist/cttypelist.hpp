template<typename T, T... Values>
using CTTypelist = Typelist<CTValue<T, Values>...>;

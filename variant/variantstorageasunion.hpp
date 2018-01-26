template<typename... Types>
union VariantStorage;

template<typename Head, typename... Tail>
union VariantStorage<Head, Tail...> {
  Head head;
  VariantStorage<Tail...> tail;
};

template<>
union VariantStorage<> {
};


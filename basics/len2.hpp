// number of elements in a raw array:
template<typename T, unsigned N>
std::size_t len (T(&)[N]) 
{ 
  return N;
}

// number of elements for a type having size_type:
template<typename T>
typename T::size_type len (T const& t) 
{ 
  return t.size();
}

// fallback for all other types:
std::size_t len (...)
{ 
  return 0;
}

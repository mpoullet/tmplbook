template<typename T>
T const& checked (T const& a, T const& b)
{
    return  test() ? a : b;
}

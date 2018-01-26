template<typename DstT, typename SrcT>
DstT implicit_cast (SrcT const& x)  // SrcT can be deduced, but DstT cannot
{
  return x;
}

int main()
{
  double value = implicit_cast<double>(-1);
}

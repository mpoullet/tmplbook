template<typename T>
class VirtualClass {
  public:
    virtual ~VirtualClass() {}
    virtual T vmem();  // Likely ERROR if instantiated without definition
};

int main()
{
   VirtualClass<int> inst;
}

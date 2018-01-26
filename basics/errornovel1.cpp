#include <string>
#include <map>
#include <algorithm>

int main()
{
  std::map<std::string,double> coll;                  
  //...
  // find the first nonempty string in coll:
  auto pos = std::find_if (coll.begin(), coll.end(),
                           [] (std::string const& s) { 
                             return s != "";
                           });
}

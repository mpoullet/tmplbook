#include "specialmemtmpl3.hpp"

int main()
{
  std::string s = "sname";
  Person p1(s);              // init with string object => calls TMPL-CONSTR
  Person p2("tmp");          // init with string literal => calls TMPL-CONSTR
  Person p3(p1);             // OK => calls COPY-CONSTR
  Person p4(std::move(p1));  // OK => calls MOVE-CONST
}

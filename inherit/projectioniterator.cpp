#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
  std::vector<Person> authors = { {"David", "Vandevoorde"},
                                  {"Nicolai", "Josuttis"},
                                  {"Douglas", "Gregor"} };

  std::copy(project(authors.begin(), &Person::firstName),
            project(authors.end(), &Person::firstName),
            std::ostream_iterator<std::string>(std::cout, "\n"));
}

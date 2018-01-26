#include <vector>
#include <algorithm>
#include <string>

int main()
{
  std::vector<std::string> strings = {"banana", "apple", "cherry"};
  std::vector<unsigned> indices = { 0, 1, 2 };
  std::sort(indices.begin(), indices.end(),
            [&strings](unsigned i, unsigned j) {
                return strings[i] < strings[j];
            });
}

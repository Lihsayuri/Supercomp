#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element
#include <vector>

int main () {
  std::vector<int> myints = {3,7,2,5,6,4,9};

  // using default comparison:
  std::cout << "Aquii "  << std::max_element(myints.begin(), myints.end()) - myints.begin()  << '\n';


  return 0;
}
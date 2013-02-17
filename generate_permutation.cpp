/*
   see http://en.cppreference.com/w/cpp/algorithm/next_permutation
*/

#include <algorithm>
#include <string>
#include <iostream>

int main()
{
  std::string s = "aba";
  std::sort(s.begin(), s.end());
  do {
    std::cout << s << '\n';
  } while(std::next_permutation(s.begin(), s.end()));
}

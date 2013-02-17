#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
int main() {
  // remove odd numbers
  std::vector<int> v{11, 22, 33, 44, 55 };
  v.erase(remove_if(begin(v), end(v),
                    [](int e){ return e % 2 == 1; }), end(v));
  std::for_each(begin(v), end(v), [](int e) { cout << e << " "; });

  // remove newline
  std::string str("abc\ndef");
  str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
  return 0;
}

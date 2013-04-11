#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ostream>
#include <iterator>
using namespace std;

template <typename ForwardIt, typename ContainerT, typename UnaryPredicate>
void segment(ForwardIt first, ForwardIt last, ContainerT& subseqs, UnaryPredicate p) {

  // loop invariant: [first, start) is segmented
  ForwardIt start = first;
  while (start != last) {
    ForwardIt end = std::find_if(start, last, p);

    if (start != end)
      subseqs.emplace_back(typename ContainerT::value_type(start, end));

    if (end != last) {
      start = end + 1;
    } else {
      start = end;
      break;
    }

  }
  // termination: start = last, thus [first, last) is segmented

}


int main() {
  string sentence = "Something in the way she moves...";
  vector<string> tokens;
  segment(sentence.begin(), sentence.end(), tokens, [](char c) { return c == ' '; });
  copy(tokens.begin(), tokens.end(), ostream_iterator<string>(cout, ", "));
  cout << endl;

  vector<int> numbers = {2, 6, 8, 9, 4, 6, 8, 3, 8, 7, 7};
  vector<vector<int>> evens;
  segment(numbers.begin(), numbers.end(), evens, [](int i) { return i % 2 != 0; });

  for (const auto e: evens) {
    copy(e.begin(), e.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
  }


  return 0;

}

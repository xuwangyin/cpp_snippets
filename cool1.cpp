/*
* inspired by https://github.com/facebook/folly/blob/master/folly/dynamic.h.
* It feels like "Iterator pattern" in GOF; the client using Foo::const_iterator 
* only need to link to Foo once Foo's internal collection changed from vector to list.
* I will name it "the iterator pattern", how do you like it?
*/

#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>
using namespace std;

class Foo {
private:
  // typedef std::list<int> Array;
  typedef std::vector<int> Array;

public:
  typedef Array::const_iterator const_iterator;
  Foo(initializer_list<int> il): array(il) { }

  const_iterator begin()  const {
    return array.begin();
  }

  const_iterator end()    const {
    return array.end();
  }

private:
  Array array;
};


int main() {
  Foo f({1, 2, 3});
  for (auto i: f)
    cout << i << endl;

  // Foo::const_iterator i;
  // for (i = f.begin(); i != f.end(); ++i) {
  //   cout << *i << endl;
  // }

  return 0;
}

#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct Foo {
  const vector<int>& getComponents() const {
    cout << "i am getComponents, return const vector<int>&" << endl;
    return stuff;
  }

  vector<int>& getComponents() {
    cout << "i am getComponents, return vector<int>" << endl;
    return stuff;
  }

  const vector<int>& getComponentsFancy() const{
    cout << "i am getComponentsFancy, return const vector<int>& with fancy" << endl;
    return stuff;
  }

  vector<int> stuff;
};

int main() {

  auto bar = [](Foo& foo,
                decltype(mem_fn(&Foo::getComponentsFancy)) getComponentsMethod=mem_fn(&Foo::getComponentsFancy)) {
    getComponentsMethod(foo);
  };

  Foo f;
  bar(f);

  bar(f, mem_fn<const vector<int>&() const>(&Foo::getComponents));

  // won't compile
  // bar(f, mem_fn<vector<int>&()>(&Foo::getComponents));

}

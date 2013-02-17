#include <cstddef>
#include <iostream>

template <size_t N> void foo(const int (&arr)[N]) {
  std::cout << "Array of size " << N << std::endl;
}

int main() {
  int a[] = {11, 22, 33, 44 };
  foo(a);
  return 0;
}

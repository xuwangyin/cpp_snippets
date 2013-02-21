#include <cstddef>
#include <iostream>

template <size_t N> void foo(const int (&arr)[N]) {
  std::cout << "Array of size " << N << std::endl;
}

template <size_t M, size_t N> void bar(const int (&arr)[M][N]) {
  std::cout << "Array of size: " << M << " * " << N << std::endl;
}

int main() {
  int a[] = {11, 22, 33, 44 };
  foo(a);

  const int M = 100; // note that it has to be const
  const int N = 10;
  int b[M][N];
  bar(b);

  return 0;
}

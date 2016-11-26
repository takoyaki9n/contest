#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  std::cin >> N;
  int a[N];
  for (size_t i = 0; i < N; i++) {
    std::cin >> a[i];
  }
  unsigned int sum = 0;
  for (size_t i = 0; i < N; i++) {
    sum = sum << 1;
    sum += a[i];
  }

  std::cout << sum << std::endl;
}

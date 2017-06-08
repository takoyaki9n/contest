#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_T 1000000001
#define MAX_N 100001

int min(int x, int y) {
  return (x < y)? x: y;
}

int main() {
  int N, T;
  std::cin >> N >> T;
  int a[N], b[N];
  for (size_t i = 0; i < N; i++) {
    std::cin >> a[i] >> b[i];
  }

  int sum = 0;
  for (size_t i = 0; i < N; i++) {
    sum += b[i];
    a[i] = a[i] - b[i];
  }

  if (sum > T) {
    std::cout << -1 << std::endl;
    return 0;
  }
  sort(a, a+N);

  int count = 0;
  for (size_t i = 0; i < N; i++) {
    sum += a[i];
    if (sum > T) {
      break;
    }
    count++;
  }
  std::cout << N - count << std::endl;
  return 0;
}

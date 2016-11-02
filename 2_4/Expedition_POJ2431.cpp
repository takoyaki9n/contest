#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

#define MAX_N (10000)
#define MAX_L (1000000)
#define MAX_P (1000000)
#define MAX_B (100)

int N, L, P;
int A[MAX_N + 1], B[MAX_N + 1];

int solve(){
  A[N] = L; B[N] = 0;
  int p = P;
  int x = 0;
  int ans = 0;

  std::priority_queue<int> pq;
  for (size_t i = 0; i <= N; i++) {
    p -= A[i] - x;
    while (p < 0) {
      if (pq.empty()) {
        return -1;
      } else {
        p += pq.top(); pq.pop();
        ans++;
      }
    }
    pq.push(B[i]);
    x = A[i];
  }
  return ans;
}

int main() {
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    int j = N - 1 - i;
    std::cin >> A[j] >> B[j];
  }
  std::cin >> L >> P;
  for (size_t i = 0; i < N; i++) {
    A[i] = L - A[i];
  }

  std::cout << solve() << std::endl;
  return 0;
}

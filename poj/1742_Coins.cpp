#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (100)
#define MAX_M (100000)
#define MAX_A (100000)
#define MAX_C (1000)

int N, M, A[MAX_N], C[MAX_C];
int dp[2][MAX_M + 1];

int main() {
  while (true) {
    std::cin >> N >> M;
    if (N == 0) break;
    for (size_t i = 0; i < N; i++) std::cin >> A[i];
    for (size_t i = 0; i < N; i++) std::cin >> C[i];

    for (size_t j = 1; j <= M; j++) dp[0][j] = -1;
    dp[0][0] = 0;

    for (size_t i = 0; i < N; i++) {
      int cur = i % 2;
      int nxt = (i + 1) % 2;
      for (size_t j = 0; j <= M; j++) dp[nxt][j] = -1;

      for (size_t j = 0; j <= M; j++) {
        if (dp[cur][j] >= 0) {
          dp[nxt][j] = C[i];
        } else if (j >= A[i] && dp[nxt][j - A[i]] > 0) {
          dp[nxt][j] = dp[nxt][j - A[i]] - 1;
        }
      }
    }

    int count = 0;
    for (size_t i = 1; i <= M; i++) {
      if (dp[N % 2][i] >= 0) count++;
    }

    std::cout << count << std::endl;
  }

  return 0;
}

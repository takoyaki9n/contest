#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_T (1000)
#define MAX_W (30)
#define INF   (MAX_T * 10 + 1)

int T, W;
int A[MAX_T];
int dp[MAX_T + 1][MAX_W + 1][2];

int main() {
  std::cin >> T >> W;
  for (size_t i = 0; i < T; i++) {
    std::cin >> A[i];
    A[i]--;
  }

  for (size_t t = 0; t <= T; t++) {
    for (size_t w = 0; w <= W; w++) {
      for (size_t p = 0; p < 2; p++) {
        dp[t][w][p] = -INF;
      }
    }
  }
  dp[0][0][0] = 0;

  for (size_t t = 1; t <= T; t++) {
    for (size_t w = 0; w <= W; w++) {
      for (size_t p = 0; p < 2; p++) {
        int v = dp[t - 1][w][p] + ((A[t - 1] == p)? 1: 0);
        if (w > 0) {
          v = max(v, dp[t - 1][w - 1][1 - p] + ((A[t - 1] == p)? 1: 0));
        }
        dp[t][w][p] = v;
      }
    }
  }

  // for (size_t t = 0; t <= T; t++) {
  //   for (size_t w = 0; w <= W; w++) {
  //     if (dp[t][w][0] < 0) {
  //       std::cout << "-";
  //     } else {
  //       std::cout << dp[t][w][0];
  //     }
  //     std::cout << ",";
  //     if (dp[t][w][1] < 0) {
  //       std::cout << "-";
  //     } else {
  //       std::cout << dp[t][w][1];
  //     }
  //     std::cout << " ";
  //   }
  //   std::cout << std::endl;
  // }

  int count = -1;
  for (size_t w = 0; w <= W; w++) {
    for (size_t p = 0; p < 2; p++) {
      count = max(count, dp[T][w][p]);
    }
  }

  std::cout << count << std::endl;

  return 0;
}

#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (200)
#define MAX_W (1000)
#define INF   (MAX_N * MAX_W + 1)

int N, W;
int dp[MAX_N + 1][MAX_W + 1], v[MAX_N], w[MAX_N];

int rec(int i, int j) {
  if (dp[i][j] >= 0) { return dp[i][j]; }
  if (i == N) {
    dp[i][j] =  0;
  } else if (j < w[i]) {
    dp[i][j] = rec(i + 1, j);
  } else {
    dp[i][j] = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  return dp[i][j];
}

int main() {
  scanf("%d %d", &N, &W);
  for (size_t i = 0; i < N; i++) {
    scanf("%d %d", &v[i], &w[i]);
  }

  for (size_t i = 0; i <= N; i++) {
    for (size_t j = 0; j <= W; j++) {
      dp[i][j] = -1;
    }
  }

  printf("%d\n", rec(0, W));

  return 0;
}

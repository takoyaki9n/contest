#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//#define MAX_N 1000000000
#define MAX_N 100
#define MAX_M 100
#define INF   2047483647

int dp0[MAX_N];
int dp1[MAX_N];

int min(int x, int y) {
  return (x < y)? x: y;
}

void init_dp(int *dp, int N) {
  for (size_t i = 0; i < N; i++) {
    dp[i] = INF;
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  int X[M];
  for (size_t i = 0; i < M; i++) {
    scanf("%d", &X[i]);
    X[i]--;
  }

  int *dq0, *dq1;
  dq0 = dp0; dq1 = dp1;
  init_dp(dp0, N);
  dq0[0] = 0;
  for (size_t i = 1; i <= M; i++) {
    for (size_t j = 0; j < N; j++) {
      for (size_t k = X[i]; k <= N; k++) {
        /* code */
      }

    }
    int *tmp = dq0;
    dq0 = dq1;
    dq1 = tmp;
    init_dp(dq1, N);
  }

  return 0;
}

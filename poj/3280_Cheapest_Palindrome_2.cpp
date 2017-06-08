#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (256)
#define MAX_M (2000)
#define MAX_COST (10000)
#define INF (MAX_COST * MAX_M * 10)

int N, M;
string ID;
int dp[MAX_M + 1][MAX_M + 1], costs[MAX_M];

int main() {
  std::cin >> N >> M;
  std::cin >> ID;
  for (size_t i = 0; i < N; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    costs[(int) c] = min(a, b);
  }

  for (size_t i = 0; i <= M; i++)
    for (size_t j = i; j <= M; j++)
      dp[i][j] = (j - i <= 1)? 0: INF;

  for (size_t l = 2; l <= M; l++) {
    for (size_t i = 0; i <= M - l; i++) {
      int j = l + i;
      dp[i][j] = min(dp[i][j - 1] + costs[(int) ID[j - 1]], dp[i + 1][j] + costs[(int) ID[i]]);
      if (ID[i] == ID[j - 1]) {
        dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
      }
    }
  }

  // for (size_t i = 0; i <= M; i++) {
  //   for (size_t j = 0; j <= M; j++) {
  //     std::cerr << dp[i][j] << "\t";
  //   }
  //   std::cerr << std::endl;
  // }

  std::cout << dp[0][M] << std::endl;

  return 0;
}

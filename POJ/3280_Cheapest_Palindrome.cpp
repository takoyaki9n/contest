#include <cstdio>
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

int lcs(string s, string t) {
  int n = s.size();
  int m = t.size();
  for (size_t i = 0; i <= n; i++)
    for (size_t j = 0; j <= m; j++)
      dp[i][j] = INF;
  dp[0][0] = 0;

  for (size_t i = 0; i <= n; i++) {
    for (size_t j = 0; j <= m; j++) {
      if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
        dp[i - 1][j - 1] = dp[i - 1][j - 1];
      }
      if (i > 0) {
        int c = (int) s[i - 1];
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + costs[c]);
      }
      if (j > 0) {
        int c = (int) t[j - 1];
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + costs[c]);
      }
    }
  }

  // for (size_t i = 0; i <= n; i++) {
  //   for (size_t j = 0; j <= m; j++) {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  return dp[n][m];
}

int main() {
  std::cin >> N >> M;
  std::cin >> ID;
  for (size_t i = 0; i < N; i++) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    costs[(int) c] = min(a, b);
//    std::cout << c << " " << costs[(int) c] << std::endl;
  }



  int cost_min = INF;
  for (size_t i = 0; i < M; i++) {
    string s = ID.substr(0, i);
    string t = ID.substr(i);
    reverse(s.begin(), s.end());
    cost_min = min(cost_min, lcs(s, t));
//    std::cout << s << ", " << t << " = " << cost_min << std::endl << std::endl;

    t = t.substr(1);
    cost_min = min(cost_min, lcs(s, t));
//    std::cout << s << ", " << t << " = " << cost_min << std::endl << std::endl;
  }

  std::cout << cost_min << std::endl;

  return 0;
}

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

//#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define INF   (1000000007)
#define MAX_N (3000)
#define MAX_M (3000)

int N, M;
ll DP[MAX_M + 1][MAX_N + 1][2];

void solve() {
  for (int j = 0; j <= N; j++)
    for (int k = 0; k < 2; k++) DP[0][j][k] = (j != 0)? k: 1 - k;
  for (int j = 0; j <= N; j++) debug_printf("%lld/%lld ", DP[0][j][0], DP[0][j][1]);
  debug_printf("\n");

  for (int i = 0; i < M; i++) {
    for (int j = 0; j <= N; j++) {
      ll d0 = 0, d1 = 0;
      if (j == 0) {
        d0 += DP[i][j][0] + DP[i][j][1] + DP[i][j + 1][0] + DP[i][j + 1][1];
      } else if (j == 1) {
        d0 += DP[i][j - 1][0] + DP[i][j - 1][1] + DP[i][j][0] + DP[i][j][1] + DP[i][j][0];
        d1 += DP[i][j][1];
        if (j < N) {
          d0 += DP[i][j + 1][0];
          d1 += DP[i][j + 1][1];
        }
      } else {
        d0 += DP[i][j - 1][0] + DP[i][j][0];
        d1 += DP[i][j - 1][1] + DP[i][j][1];
        if (j < N) {
          d0 += DP[i][j + 1][0] + DP[i][j][0];
          d1 += DP[i][j + 1][1] + DP[i][j][1];
        }
      }
      DP[i + 1][j][0] = d0 % INF;
      DP[i + 1][j][1] = d1 % INF;
      debug_printf("%lld/%lld ", d0, d1);
    }
    debug_printf("\n");
  }

  ll ans = 0;
  for (int j = 0; j <= N; j++) ans = (ans + DP[M][j][0]) % INF;
  printf("%lld\n", ans);
}

int main() {
  cin >> N >> M;

  solve();

  return 0;
}

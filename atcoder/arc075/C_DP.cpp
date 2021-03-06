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

#define DEBUG
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

#define FST first
#define SND second

#define MAX_N   (100)                  // 10^5
#define MAX_S   (100)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, S[MAX_N], SMX;
bool DP[2][MAX_N * MAX_S + 1];

void solve() {
  for (int i = 0; i <= N * SMX; i++) DP[0][i] = false;
  DP[0][0] = true;

  for (int i = 0; i < N; i++) {
    int x = i % 2, y = (i + 1) % 2;
    for (int j = 0; j <= N * SMX; j++) DP[y][j] = false;
    for (int j = 0; j <= N * SMX; j++) {
      DP[y][j] = DP[x][j];
      if (j - S[i] >= 0) DP[y][j] |= DP[x][j - S[i]];
    }
    // for (int j = 0; j <= N * SMX; j++) cout << DP[y][j] << " ";
    // cout << endl;
  }

  ll ans = 0;
  for (int i = N * SMX; i >= 0; i--) {
    if (i % 10 != 0 && DP[N % 2][i]) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  SMX = 0;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
    SMX = max(SMX, S[i]);
  }

  solve();

  return 0;
}

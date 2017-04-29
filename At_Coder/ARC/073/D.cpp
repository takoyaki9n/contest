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

#define INF   (1e9 + 7)
#define MAX_N (100)


ll N, W;
ll X[MAX_N], Y[MAX_N];

void solve() {
  map<ll, ll> dp[2];
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    int x = i % 2;
    int y = (i + 1) % 2;
    dp[y].clear();
    for (auto wv : dp[x]) {
      ll w = wv.first;
      ll v = wv.second;
      debug_printf("%lld:%lld ", w, v);
      dp[y][w] = max(v, dp[y][w]);
      if (w + X[i] <= W){
        dp[y][w + X[i]] = max(v + Y[i], dp[y][w + X[i]]);
      }
    }
    debug_printf("\n");
  }

  ll ans = 0;
  for (auto wv : dp[N % 2]) {
    if (wv.first <= W) {
      ans = max(ans, wv.second);
      debug_printf("%lld:%lld ", wv.first, wv.second);
    }
  }
  debug_printf("\n");

  cout << ans << endl;
}

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  solve();

  return 0;
}

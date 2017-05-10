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

#define FST first
#define SND second

#define MAX_N   (100000)                  // 10^5
#define MAX_LOGN   (17)
#define MAX_M   (3000000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll N, M, X, D;
pair<string, int> S[MAX_N];
int MP[MAX_N];
int ST[MAX_LOGN][MAX_N];

int common_prefix_size(const string &s, const string &t) {
  int n = min(s.size(), t.size());
  for (int i = 0; i < n; i++) if (s[i] != t[i]) return i;
  return n;
}

void contruct_sparse_table() {
  for (int i = 0; i < N - 1; i++) ST[0][i] = common_prefix_size(S[i].FST, S[i + 1].FST);

  for (int k = 1; (1 << k) < N; k++) {
    int p = 1 << (k - 1);
    for (int i = 0; i < N - 1; i++) {
      ST[k][i] = ST[k - 1][i];
      if (i + p < N - 1) ST[k][i] = min(ST[k][i], ST[k - 1][i + p]);
    }
  }

#ifdef DEBUG
  for (int k = 0; (1 << k) < N; k++) {
    for (int i = 0; i < N - 1; i++)
      debug_printf("%d ", ST[k][i]);
    debug_printf("\n");
  }
#endif
}

ll query(int l, int r) {
  int d = r - l;
  if (d == 0) return S[l].FST.size();
  int k = 0;
  while ((1 << k) <= d) k++;
  k--;
  int p = 1 << k;
  return min(ST[k][l], ST[k][r - p]);
}

void solve() {
  sort(S, S + N);
  for (int i = 0; i < N; i++) MP[S[i].SND] = i;

  contruct_sparse_table();
  ll ans = 0;
  for (int i = 0; i < M; i++) {
    ll l = (X / (N - 1)) + 1;
    ll r = (X % (N - 1)) + 1;
    if (l > r)
      swap(l, r);
    else
      r++;
    X = (X + D) % (N * (N - 1));
    l--; r--;

    l = MP[l]; r = MP[r];
    if (l > r) swap(l, r);
    debug_printf("S[%lld] = %s, S[%lld] = %s\n", l, S[l].FST.c_str(), r, S[r].FST.c_str());
    ans += query(l, r);
  }
  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i].FST;
    S[i].SND = i;
  }
  cin >> M >> X >> D;

  solve();

  return 0;
}

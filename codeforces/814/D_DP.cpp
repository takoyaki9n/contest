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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (1000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

struct circle {
  ll x, y, r;
  circle() : x(0), y(0), r(0) {}
  circle(ll x, ll y, ll r) : x(x), y(y), r(r) {}
};

int N;
circle C[MAX_N];
Vi ROOTS;
Vi CHLD[MAX_N];
ll DP[MAX_N][2][2];
const double PI = acos(-1);

bool cmp(const circle &c1, const circle &c2) {
  return c1.r > c2.r;
}

bool is_inside(const circle &c1, const circle &c2) {
  ll dx = c1.x - c2.x, dy = c1.y - c2.y;
  ll dr2 = dx * dx + dy * dy;
  return c1.r < c2.r && dr2 < c2.r * c2.r;
}

ll dfs(int x, int a, int b) {
  debug_printf("%d %d %d\n", x, a, b);
  if (DP[x][a][b] >= 0) return DP[x][a][b];

  ll sqr = C[x].r * C[x].r;
  ll sa = sqr * ((a == 0)? 1: -1);
  ll sb = sqr * ((b == 0)? 1: -1);
  for (auto y : CHLD[x]) {
    sa += dfs(y, 1 ^ a, b);
    sb += dfs(y, a, 1 ^ b);
  }

  DP[x][a][b] = max(sa, sb);
  return DP[x][a][b];
}

void solve() {

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    printf("%lld %lld %lld\n", C[i].x, C[i].y, C[i].r);
  }
#endif

  for (int i = 0; i < N; i++) {
    int p = i;
    for (int j = 0; j < N; j++) {
      if (is_inside(C[i], C[j])) {
        if (p == i || C[j].r < C[p].r) p = j;
      }
    }
    if (p == i) ROOTS.push_back(i);
    else CHLD[p].push_back(i);
  }

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    cout << i <<  " -> ";
    for (int j = 0; j < CHLD[i].size(); j++) cout << CHLD[i][j] << " ";
    cout << endl;
  }
#endif

  memset(DP, -1, sizeof(DP));

  ll ans = 0;
  for (auto x : ROOTS) ans += dfs(x, 0, 0);

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    cout << i <<  ": ";
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        cout << DP[i][j][k] << " ";
    cout << endl;
  }
#endif

  printf("%.10f\n", ans * PI);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    ll x, y, r;
    cin >> x >> y >> r;
    C[i] = circle(x, y, r);
  }

  solve();

  return 0;
}

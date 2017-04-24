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

#define BASE  (1000000000 + 7)
#define MAX_N (1000000000)
#define MAX_M (100000)

int N, M;
int X[MAX_M + 1];
ll A[3] = {1, 3, 1};
ll P[3][3] = {
  {2, 1, 0},
  {3, 1, 2},
  {1, 0, 1}
}, Q[3][3] = {
  {1, 1, 0},
  {0, 1, 2},
  {0, 0, 1}
}, R[3][3];

void mat_print3x3(ll a[3][3]) {
#ifdef DEBUG
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      debug_printf("%lld ", a[i][j]);
    }
    debug_printf("\n");
  }
#endif
}

void mat_copy3x3(ll a[3][3], ll b[3][3]) {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) a[i][j] = b[i][j];
}

void mat_prod3x3(ll a[3][3], ll b[3][3], ll c[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = 0;
      for (int k = 0; k < 3; k++) a[i][j] = (a[i][j] + b[i][k] * c[k][j]) % BASE;
    }
  }
}

void mat_pow3x3(ll a[3][3], ll b[3][3], ll n) {
  if (n == 0) {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) a[i][j] = (i == j)? 1: 0;
  } else {
    ll c[3][3];
    mat_pow3x3(c, b, n / 2);
    mat_prod3x3(a, c, c);
    if (n % 2 == 1) {
      mat_copy3x3(c, a);
      mat_prod3x3(a, b, c);
    }
  }
}

void solve() {
  mat_pow3x3(R, P, X[0] - 1);
  for (int i = 1; i <= M; i++) {
    ll s[3][3], t[3][3];
    mat_prod3x3(s, R, Q);
    mat_pow3x3(t, P, X[i] - X[i - 1] - 1);
    mat_prod3x3(R, s, t);
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++) ans = (ans + R[0][i] * A[i]) % BASE;

  printf("%lld\n", ans);
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> X[i];
  X[M] = N;

  solve();

  return 0;
}

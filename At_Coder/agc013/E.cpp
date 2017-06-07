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
typedef vector<Vl> VVl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define BASE  (1000000000 + 7)
#define MAX_N (1000000000)
#define MAX_M (100000)
#define K     (3)

int N, M;
int X[MAX_M + 1];
ll A[K] = {1, 3, 1};
ll P1[K][K] = {
  {2, 1, 0},
  {3, 1, 2},
  {1, 0, 1}},
P[31][K][K] ,
Q[K][K] = {
  {1, 1, 0},
  {0, 1, 2},
  {0, 0, 1}},
R[K][K];

void mat_print(ll a[K][K]) {
#ifdef DEBUG
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      debug_printf("%lld ", a[i][j]);
    }
    debug_printf("\n");
  }
#endif
}

void mat_copy(ll a[K][K], ll b[K][K]) {
  for (int i = 0; i < K; i++)
    for (int j = 0; j < K; j++) a[i][j] = b[i][j];
}

void mat_prod(ll a[K][K], ll b[K][K], ll c[K][K]) {
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      a[i][j] = 0;
      for (int k = 0; k < K; k++) a[i][j] = (a[i][j] + b[i][k] * c[k][j]) % BASE;
    }
  }
}

void build_pow_P() {
  for (int i = 0; i < K; i++) {
    for (int j = 0; j < K; j++) {
      P[0][i][j] = (i == j)? 1: 0;
      P[1][i][j] = P1[i][j];
    }
  }

  for (int i = 2; i < 31; i++) mat_prod(P[i], P[i - 1], P[i - 1]);
}

void pow_P(ll a[K][K], ll n) {
  for (int i = 0; i < K; i++)
    for (int j = 0; j < K; j++) a[i][j] = P[0][i][j];

  for (int i = 1; i < 31; i++) {
    if (n == 0) break;
    if ((n & 1) != 0) {
      ll b[K][K];
      mat_prod(b, a, P[i]);
      mat_copy(a, b);
    }
    n >>= 1;
  }
}

void solve() {
  pow_P(R, X[0] - 1);
  for (int i = 1; i <= M; i++) {
    ll s[K][K], t[K][K];
    pow_P(s, X[i] - X[i - 1] - 1);
    mat_prod(t, R, Q);
    mat_prod(R, t, s);
  }

  ll ans = 0;
  for (int i = 0; i < 3; i++) ans = (ans + R[0][i] * A[i]) % BASE;

  printf("%lld\n", ans);
}

int main() {
  build_pow_P();

  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> X[i];
  X[M] = N;

  solve();

  return 0;
}

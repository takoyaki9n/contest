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

int N, M;
int X[MAX_M + 1];
Vl A{1, 3, 1};
VVl P1{
  {2, 1, 0},
  {3, 1, 2},
  {1, 0, 1}},
P[31],
Q{{1, 1, 0},
  {0, 1, 2},
  {0, 0, 1}},
R(3, Vl(3));

void mat_print(VVl &a) {
#ifdef DEBUG
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      debug_printf("%lld ", a[i][j]);
    }
    debug_printf("\n");
  }
#endif
}

void mat_prod(VVl &a, VVl b, VVl c) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      a[i][j] = 0;
      for (int k = 0; k < b[0].size(); k++) a[i][j] = (a[i][j] + b[i][k] * c[k][j]) % BASE;
    }
  }
}

void build_pow_P() {
  for (int i = 0; i < 31; i++) P[i] = VVl(3, Vl(3));

  for (int i = 0; i < P[0].size(); i++) {
    for (int j = 0; j < P[0][0].size(); j++) {
      P[0][i][j] = (i == j)? 1: 0;
      P[1][i][j] = P1[i][j];
    }
  }
  for (int i = 2; i < 31; i++) mat_prod(P[i], P[i - 1], P[i - 1]);
}

void pow_P(VVl &a, ll n) {
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[0].size(); j++) a[i][j] = P[0][i][j];

  for (int i = 1; i < 31; i++) {
    if (n == 0) break;
    if ((n & 1) != 0)
      mat_prod(a, a, P[i]);
    n >>= 1;
  }
}

void solve() {
  pow_P(R, X[0] - 1);
  for (int i = 1; i <= M; i++) {
    VVl s(3, Vl(3));
    mat_prod(R, R, Q);
    pow_P(s, X[i] - X[i - 1] - 1);
    mat_prod(R, R, s);
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

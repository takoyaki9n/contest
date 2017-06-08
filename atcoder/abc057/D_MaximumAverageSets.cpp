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
#define MAX_N (50)

int N, A, B;
ll V[MAX_N];
ll C[MAX_N + 1][MAX_N + 1];

void solve() {
  sort(V, V + N);
  double ave = 0.0;
  for (int i = 0; i < A; i++) ave += V[N - i - 1];
  ave /= A;

  ll x = V[N - A];
  int lb = (int) (lower_bound(V, V + N, x) - V);
  int ub = (int) (upper_bound(V, V + N, x) - V);
  debug_printf("x = %lld, ub = %d, lb = %d\n", x, ub, lb);

  ll comb = 0;
  if (x == V[N - 1]) {
    int p = ub - lb;
    for (int q = A; q <= min(B, N - lb); q++)
      comb += C[p][q];
  } else {
    int p = ub - lb;
    int q = A - (N - ub);
    debug_printf("p = %d, q = %d\n", p, q);
    comb = C[p][q];
  }

  printf("%f\n", ave);
  printf("%lld\n", comb);
}

int main() {
  scanf("%d %d %d", &N, &A, &B);
  for (int i = 0; i < N; i++) scanf("%lld", &V[i]);

  C[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    C[i][0] = 1; C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    // for (int j = 0; j <= i; j++) debug_printf("%lld ", C[i][j]);
    // debug_printf("\n");
  }

  solve();

  return 0;
}

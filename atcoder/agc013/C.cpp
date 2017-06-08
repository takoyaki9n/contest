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

#define INF   (1e9 + 7)
#define MAX_N (100000)

int N, L, T;
ll X[MAX_N], P[MAX_N];
int W[MAX_N];

void solve() {
  for (int i = 0; i < N; i++) {
    P[i] = W[i] * T + X[i];
    P[i] = ((P[i] % L) + L) % L;
  }

  int cnt = 0;
  int round = 2 * T / L;
  int rest = 2 * T % L;
  for (int i = 1; i < N; i++) {
    if (W[i] != W[0]) {
      cnt += round;
      int d = X[i] - X[0];
      if (W[0] < 0) d = L - d;
      if (d < rest) cnt++;
    }
  }

  int p0 = P[0], i0;
  sort(P, P + N);
  if (W[0] > 0) {
    i0 = (int) (lower_bound(P, P + N, p0) - P);
  } else {
    i0 = (int) (upper_bound(P, P + N, p0) - P) - 1;
  }
  i0 = i0 - W[0] * cnt;
  i0 = ((i0 % N) + N) % N;

  for (int i = 0; i < N; i++) {
    printf("%lld\n", P[(i + i0) % N]);
  }
}

int main() {
  cin >> N >> L >> T;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> W[i];
    W[i] = (W[i] == 1)? 1: -1;
  }

  solve();

  return 0;
}

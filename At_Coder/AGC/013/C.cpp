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
#define MAX_N (100000)

int N, L, T;
ll X[MAX_N], P[MAX_N];
int W[MAX_N];

void solve() {
  for (int i = 0; i < N; i++) P[i] = X[i] + W[i] * T;

  int id = 0;
  for (int i = 1; i < N; i++) {
    if (W[0] == W[i]) continue;

  }
  id = -id % N;
  id = (id + N) % N;

  for (int i = 0; i < N; i++) {
    P[i] = P[i] % L;
    P[i] = (P[i] + L) % L;
  }

  sort(P, P + N);
  for (int i = 0; i < N; i++) {
    printf("%lld\n", P[(id + i) % N]);
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

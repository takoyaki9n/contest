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

int N;
ll A[MAX_N];

void solve() {
  sort(A, A + 3 * N, std::greater<int>());

  for (int i = 0; i < 3 * N; i++) debug_printf("%lld ", A[i]);
  debug_printf("\n");

  ll ans = 0;
  for (int i = 0; i < N; i++) ans += A[2 * i + 1];

  printf("%lld\n", ans);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < 3 * N; i++) scanf("%lld", &A[i]);

  solve();

  return 0;
}

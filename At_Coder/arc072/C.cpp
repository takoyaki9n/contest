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

int N, A[MAX_N], S[MAX_N];

ll calc(ll sum, ll ans) {
  for (int i = 1; i < N; i++) {
    ll s = sum;
    sum += A[i];
    if (s * sum < 0) continue;
    ans += abs(sum) + 1;
    sum = (s < 0)? 1: -1;
  }
  return ans;
}

void solve() {
  ll ans;
  if (A[0] == 0) {
    ans = min(calc(1, 1), calc(-1, 1));
  } else if (A[0] > 0) {
    ans = min(calc(A[0], 0), calc(-1, abs(A[0]) + 1));
  } else {
    ans = min(calc(A[0], 0), calc(1,  abs(A[0]) + 1));
  }
  printf("%lld\n", ans);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  solve();

  return 0;
}

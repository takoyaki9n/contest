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
#define MAX_N (200000)


ll N, T;
ll X[MAX_N];

void solve() {
  ll ans = 0;
  for (int i = 0; i < N - 1; i++) {
    ans += min(T, X[i + 1] - X[i]);
  }
  ans += T;

  cout << ans << endl;
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> X[i];

  solve();

  return 0;
}

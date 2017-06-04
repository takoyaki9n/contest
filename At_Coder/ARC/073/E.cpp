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
#include <unordered_set>

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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (200000)                  // 10^5
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
Pl V[MAX_N];

ll calc_min_score() {
  if (N <= 1) return 0;

  ll rmn = INFL, rmx = 0, bmn = INFL, bmx = 0;
  for (int i = 0; i < N; i++) {
    if (V[i].FST > V[i].SND) swap(V[i].FST, V[i].SND);
    rmn = min(rmn, V[i].FST);
    rmx = max(rmx, V[i].FST);
    bmn = min(bmn, V[i].SND);
    bmx = max(bmx, V[i].SND);
  }
  ll ans = (rmx - rmn) * (bmx - bmn);

  sort(V, V + N);

  int imx = -1;
  for (int i = N - 1; i > 0; i--) {
    if (V[i].SND == bmx) {
      imx = i;
      break;
    }
  }
  if (imx < 0) return ans;

  bmn = rmn;
  ll mn = V[0].SND;
  rmx = max(V[0].SND, rmx);
  ans = min(ans, (rmx - rmn) * (bmx - bmn));
  for (int i = 1; i < imx; i++) {
    mn = min(V[i].SND, mn);
    rmn = min(mn, V[i + 1].FST);
    rmx = max(V[i].SND, rmx);
    ans = min(ans, (rmx - rmn) * (bmx - bmn));
  }

  return ans;
}

void solve() {
  cout << calc_min_score() << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> V[i].FST >> V[i].SND;

  solve();

  return 0;
}
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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (100000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, C, D, CMAX, DMAX;
vector<Pi> FC, FD;

int find_max_pair(vector<Pi> &f, int m) {
  int l = 0, r = f.size() - 1;
  int b = 0, i = -1;
  while (l < r) {
    if (f[l].FST + f[r].FST <= m) {
      if (i >= 0 && f[i].FST + f[l].FST <= m) b = max(b, f[i].SND + f[l].SND);
      if (i < 0 || f[i].SND < f[l].SND) i = l;
      b = max(b, f[i].SND + f[r].SND);
      l++;
    } else {
      if (i >= 0 && f[i].FST + f[r].FST <= m) b = max(b, f[i].SND + f[r].SND);
      r--;
    }
  }
  return b;
}

void solve() {
  sort(FC.begin(), FC.end());
  sort(FD.begin(), FD.end());

  int ans = (CMAX > 0 && DMAX > 0)? CMAX + DMAX: 0;
  ans = max(ans, find_max_pair(FC, C));
  ans = max(ans, find_max_pair(FD, D));

  cout << ans << endl;
}

int main() {
  CMAX = DMAX = 0;
  cin >> N >> C >> D;
  for (int i = 0; i < N; i++) {
    int b, p;
    char t;
    cin >> b >> p >> t;
    if (t == 'C' && p <= C) {
      FC.push_back(Pl(p, b));
      CMAX = max(CMAX, b);
    }
    if (t == 'D' && p <= D) {
      FD.push_back(Pl(p, b));
      DMAX = max(DMAX, b);
    }
  }

  solve();

  return 0;
}

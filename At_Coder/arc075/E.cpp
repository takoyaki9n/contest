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

#define MAX_N   (200000)                  // 10^5
#define MAX_K   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll N, K;
ll CNT[MAX_N + 1];
Pl P[MAX_N + 1];

void merge(int l, int r) {
  if (r - l <= 1) return;
  int m = (l + r) / 2;
  merge(l, m); merge(m, r);

  int nl = m - l, nr = r - m;
  vector<Pl> vl(nl), vr(nr);
  for (int i = 0; i < nl; i++) vl[i] = P[l + i];
  for (int i = 0; i < nr; i++) vr[i] = P[m + i];

  int il = 0, ir = 0;
  while(true) {
    if (il >= nl && ir >= nr) {
      break;
    } else if (il >= nl || (ir < nr && vr[ir].FST >= vl[il].FST)){
      P[l + il + ir] = vr[ir]; ir++;
    } else {
      CNT[vl[il].SND] += ir;
      P[l + il + ir] = vl[il]; il++;
    }
  }
}

void solve() {
  for (int i = 0; i < N + 1; i++) CNT[i] = 0;

  merge(0, N + 1);

  #ifdef DEBUG
  for (int i = 0; i < N + 1; i++) cout << CNT[i] << " ";
  cout << endl;
  #endif

  ll ans = 0;
  for (int i = 0; i < N + 1; i++) ans += CNT[i];

  cout << ans << endl;
}

int main() {
  cin >> N >> K;
  P[0] = Pl(0, 0);
  ll sum = 0;
  for (int i = 1; i <= N; i++) {
    ll a;
    cin >> a;
    sum += a;
    P[i] = Pl(sum - K * i, i);
  }

#ifdef DEBUG
  for (int i = 0; i < N + 1; i++) cout << P[i].FST << " ";
  cout << endl;
#endif

  solve();

  return 0;
}

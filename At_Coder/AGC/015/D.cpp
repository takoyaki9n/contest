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

#define FST first
#define SND second

#define MAX_N   (2000)                  // 10^3
#define MAX_Q   (200000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll A, B;
string S[MAX_N];

ll calc() {
  ll r = 1L << 61;
  while (r > 0) {
    ll da = A & r;
    ll db = B & r;
    if (da != db) break;
    r >>= 1;
  }
  if (r == 0) return 1;

  if (A > B) swap(A, B);
  ll mask = (r << 1) - 1;
  A &= mask; B &= mask;

  ll k = r >> 1;
  while (k > 0) {
    ll db = B & k;
    if (db != 0) break;
    k >>= 1;
  }
  r <<= 1; k <<= 1;
  if (k == 0) k = 1;

  ll l1 = A, r1 = (r >> 1) + k;
  ll l2 = A + (r >> 1), r2 = r;
  if (l2 <= r1) {
    return max(r1, r2) - min(l1, l2);
  } else {
    return (r1 - l1) + (r2 - l2);
  }
}

void solve() {
  ll ans = calc();

  cout << ans << endl;
}

int main() {
  cin >> A >> B;

  solve();

  return 0;
}

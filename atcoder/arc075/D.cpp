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

#define MAX_N   (100000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll N, A, B, C;
ll H[MAX_N], H2[MAX_N];

bool check(ll k) {
  for (int i = 0; i < N; i++) {
    H2[i] = max(0LL, H[i] - k * B);
  }
  ll x = 0;
  for (int i = 0; i < N; i++) {
    x += (H2[i] + C - 1) / C;
  }
  return x <= k;
}

void solve() {
  sort(H, H + N);

  ll kl = -1, kr = INFI;
  while (kr - kl > 1) {
    ll km = (kl + kr) / 2;
    if (check(km)) {
      kr = km;
    } else {
      kl = km;
    }
  }

  cout << kr << endl;
}

int main() {
  cin >> N >> A >> B;
  C = A - B;
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  solve();

  return 0;
}

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
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

const int N = 3;
ll A[N], B[N];

void solve() {
  ll ans = 0;
  sort(A, A + N);
  while (true) {
    ll mn = INFL, mx = -1;
    for (int i = 0; i < N; i++) {
      if (A[i] % 2 > 0) {
        cout << ans << endl;
        return;
      }
      mn = min(mn, A[i]);
      mx = max(mx, A[i]);
    }
    if (mx - mn < 2) break;

    for (int i = 0; i < N; i++) {
      B[i] = 0;
      for (int j = 0; j < N; j++) if (i != j) B[i] += A[j];
    }
    for (int i = 0; i < N; i++) A[i] = B[i] / (N - 1);

    ans++;
  }
  cout << -1 << endl;
}

int main() {
  for (int i = 0; i < N; i++) cin >> A[i];

  solve();

  return 0;
}
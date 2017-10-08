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
using namespace std;

// #define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

ll MOD(ll x, ll y) { return (x % y + y) % y; }
ll DIV(ll x, ll y) { return (x - MOD(x, y)) / y; }

ll N, C, L[MAX_N];

void solve() {
  sort(L, L + N);
  int l = 0, r = N - 1;
  int ans = 0;
  while(l <= r) {
    #ifdef DEBUG
    cout << l << "," << r << endl;
    #endif
    if (L[l] + L[r] + 1 <= C) {
      #ifdef DEBUG
      cout << L[l] << " " << L[r] << endl;
      #endif
      l++; r--;
    } else {
      #ifdef DEBUG
      cout << L[r] << endl;
      #endif
      r--;
    }
    ans++;
  }
  cout << ans << endl;
}

int main() {
  cin >> N >> C;
  for (int i = 0; i < N; i++) cin >> L[i];

  solve();

  return 0;
}

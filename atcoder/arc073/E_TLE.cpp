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

typedef struct{ ll rl, rr, bl, br; } range;

#define FST first
#define SND second

#define MAX_N   (200000)                  // 10^5
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
ll X[MAX_N], Y[MAX_N];

ll score(range r) {
  return (r.rr - r.rl) * (r.br - r.bl);
}

class Compare {
public:
    bool operator () (const range &r1, const range &r2) {
      return score(r1) > score(r2);
    }
};

void solve() {
  set<range, Compare> rngs[2];
  range rng = {X[0], X[0], Y[0], Y[0]};
  rngs[0].insert(rng);
  for (int i = 1; i < N; i++) {
    int x = (i - 1) % 2, y = i % 2;
    rngs[y].clear();
    for (auto r : rngs[x]) {
      range r0 = {min(X[i], r.rl), max(X[i], r.rr), min(Y[i], r.bl), max(Y[i], r.br)};
      range r1 = {min(Y[i], r.rl), max(Y[i], r.rr), min(X[i], r.bl), max(X[i], r.br)};
      rngs[y].insert(r0);
      rngs[y].insert(r1);
      debug_printf("([%lld,%lld] [%lld,%lld]) ", r.rl, r.rr, r.bl, r.br);
    }
    debug_printf("\n");
  }

  ll ans = INFL;
  for (auto r : rngs[(N - 1) % 2]) {
    ans = min(ans, score(r));
    debug_printf("([%lld,%lld] [%lld,%lld]) ", r.rl, r.rr, r.bl, r.br);
  }
  debug_printf("\n");

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  solve();

  return 0;
}
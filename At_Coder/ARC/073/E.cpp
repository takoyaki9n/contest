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

void solve() {
  range rng = {X[0], X[0], Y[0], Y[0]};
  for (int i = 1; i < N; i++) {
    range rng1 = {min(X[i], rng.rl), max(X[i], rng.rr), min(Y[i], rng.bl), max(Y[i], rng.br)};
    range rng2 = {min(Y[i], rng.rl), max(Y[i], rng.rr), min(X[i], rng.bl), max(X[i], rng.br)};
    rng = (score(rng1) < score(rng2))? rng1: rng2;
  }

  cout << score(rng) << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

  solve();

  return 0;
}

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

// const int MAX_F = 3000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int A, B, C, D, E, F;
int MXX, MXY;
set<Pi> PAIRS;

int cmp_conc(int x, int y, int a, int b) {
  if (x + y + a + b == 0) return 0;
  if (x + y == 0) return -1;
  if (a + b == 0) return 1;
  return y * (a + b) - b * (x + y);
}

void dfs(int x, int y) {
  if (cmp_conc(MXX, MXY, 100, E) == 0) return;

  if (x + y > F) return;
  if (cmp_conc(x, y, 100, E) > 0) return;
  if (PAIRS.find(Pi(x, y)) != PAIRS.end()) return;

  debug_printf("%d %d\n", x, y);

  PAIRS.insert(Pi(x, y));
  if (cmp_conc(x, y, MXX, MXY) > 0) {
    MXX = x; MXY = y;
  }

  dfs(x, y + C);
  dfs(x, y + D);
  dfs(x + 100 * A, y);
  dfs(x + 100 * B, y);
}

void solve() {
  if (A < B) swap(A, B);
  if (C < D) swap(C, D);
  MXX = MXY = 0;

  dfs(0, 0);

  cout << MXX + MXY << " " << MXY << endl;
}

int main() {
  cin >> A >> B >> C >> D >> E >> F;

  solve();

  return 0;
}

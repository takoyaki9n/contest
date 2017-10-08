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

#define DEBUG
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

const int MAX_H = 200;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

ll MOD(ll x, ll y) { return (x % y + y) % y; }
ll DIV(ll x, ll y) { return (x - MOD(x, y)) / y; }

ll A, B, H, W;
char MAP[MAX_H + 1][MAX_H + 1];

bool is2v(int r, int c) {
  bool flag0 = (MAP[r][c] == 'S') && (MAP[H - r - 1][c] == 'S');
  bool flag1 = (MAP[r][W - c - 1] == 'S') && (MAP[H - r - 1][W - c - 1] == 'S');
  return flag0 || flag1;
}

bool is2h(int r, int c) {
  bool flag0 = (MAP[r][c] == 'S') && (MAP[r][W - c - 1] == 'S');
  bool flag1 = (MAP[H - r - 1][c] == 'S') && (MAP[H - r - 1][W - c - 1] == 'S');
  return flag0 || flag1;
}

ll calc() {
  ll c4 = 0, c3 = 0, c2v = 0, c2h = 0;

  bool fv = true, fh = true;
  for (int i = 0; i < H / 2; i++) {
    for (int j = 0; j < W / 2; j++) {
      int cnt = 0;
      if (MAP[i][j] == 'S') cnt++;
      if (MAP[H - i - 1][j] == 'S') cnt++;
      if (MAP[i][W - j - 1] == 'S') cnt++;
      if (MAP[H - i - 1][W - j - 1] == 'S') cnt++;

      if (cnt == 4) {
        c4++;
      } else if (cnt == 3) {
        c3++;
        fv = fh = false;
      } else if (cnt == 2) {
        if (is2v(i, j)) {
          c2v++;
          fh = false;
        } else if (is2h(i, j)) {
          c2h++;
          fv = false;
        } else {
          fv = fh = false;
        }
      } if (cnt == 1) {
        fv = fh = false;
      }
    }
  }

  ll ansv = (c2v + c3) * A + c4 * max(2 * A + B, A + 2 * B) + A + B;
  if (fh && fv) {
    ansv -= A + B;
  } else if (fv) {
    ansv -= A;
  }

  ll ansh = (c2h + c3) * B + c4 * max(2 * A + B, A + 2 * B) + A + B;
  if (fh && fv) {
    ansh -= A + B;
  } else if (fh) {
    ansh -= B;
  }

  return max(ansv, ansh);
}

void solve() {
  cout << calc() << endl;
}

int main() {
  cin >> H >> W;
  cin >> A >> B;
  for (int i = 0; i < H; i++) cin >> MAP[i];

  solve();

  return 0;
}

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

const int MAX_H = 500;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

ll MOD(ll x, ll y) { return (x % y + y) % y; }
ll DIV(ll x, ll y) { return (x - MOD(x, y)) / y; }

string COLOR = "RGBY";

int H, W, D;
char MAP[MAX_H][MAX_H + 1];

void solve() {
  for (int i = 0; i < H; i++)
    for (int j = 0; j <= W; j++) MAP[i][j] = '\0';

  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      int x = r + c, y = r - c;
      int z = DIV(2 * x + D - 1, 2 * D);
      int w = DIV(2 * y + D - 1, 2 * D);
      z = MOD(z, 2);
      w = MOD(w, 2);
      #ifdef DEBUG
      cout << r << " " << c << endl;
      cout << x << " " << y << endl;
      cout << z << " " << w << endl;
      cout << endl;
      #endif
      int k = 2 * z + w;
      MAP[r][c] = COLOR[k];
    }
  }

  for (int i = 0; i < H; i++)
    cout << MAP[i] << endl;
}

int main() {
  cin >> H >> W >> D;

  solve();

  return 0;
}
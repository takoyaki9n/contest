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

int H, W;

int split_T(int x, int y, int w, int h) {
  int s1 = x * h;
  int s2 = (w - x) * y;
  int s3 = (w - x) * (h - y);
  int d1 = abs(s1 - s2);
  int d2 = abs(s2 - s3);
  int d3 = abs(s3 - s1);
  return max(d1, max(d2, d3));
}

int split_choco() {
  int ans = INFI;
  if (H % 3 == 0) return 0;
  ans = min(ans, W);
  if (W % 3 == 0) return 0;
  ans = min(ans, H);
  int x = W / 3;
  int y = H / 2;
  ans = min(ans, split_T(x, y, W, H));
  ans = min(ans, split_T(x + 1, y, W, H));
  x = W / 2;
  y = H / 3;
  ans = min(ans, split_T(y, x, H, W));
  ans = min(ans, split_T(y + 1, x, H, W));
  return ans;
}

void solve() {
  int ans = split_choco();
  cout << ans << endl;
}

int main() {
  cin >> H >> W;

  solve();

  return 0;
}

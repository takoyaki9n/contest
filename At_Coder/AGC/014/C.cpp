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

#define MAX_H   (800)                  // 10^5
#define MAX_N   (100000)                  // 10^5
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll H, W, K;
string MAP[MAX_H];
int DIST[MAX_H][MAX_H];

bool is_inside(int i, int j) {
  return 0 <= i && i < H && 0 <= j && j < W;
}

ll min_turn() {
  int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  queue<Pi> que;
  vector<Pi> cell;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      DIST[i][j] = INFI;
      if (MAP[i][j] == 'S') {
        que.push(Pi(i, j));
        cell.push_back(Pi(i, j));
        DIST[i][j] = 0;
      }
    }
  }

  while (!que.empty()) {
    Pi p = que.front(); que.pop();
    int r = p.FST, c = p.SND;
    for (int i = 0; i < 4; i++) {
      int rx = r + dir[i][0], cx = c + dir[i][1];
      if (is_inside(rx, cx)) {
        int dist = DIST[r][c] + 1;
        if (MAP[rx][cx] == '.' && dist < DIST[rx][cx] && dist <= K) {
          DIST[rx][cx] = dist;
          que.push(Pi(rx, cx));
          cell.push_back(Pi(rx, cx));
        }
      }
    }
  }

  ll mn = INFI;
  for (auto p : cell) {
    int r = p.FST, c = p.SND;
    ll vals[4] = {r, c, H - 1 - r, W - 1 - c};
    for (int i = 0; i < 4; i++) mn = min(mn, vals[i]);
  }

  return (mn + 2 * K - 1) / K;
}

void solve() {
  ll ans = min_turn();
  cout << ans << endl;
}

int main() {
  cin >> H >> W >> K;

  for (int i = 0; i < H; i++) cin >> MAP[i];

  solve();

  return 0;
}
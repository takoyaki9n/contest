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
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;
typedef pair<ll, Pi> Pli;

#define INF   (1e16 + 7)
#define MAX_T (1e9)
#define MAX_H (10)
#define MAX_W (10)

int H, W;
ll T;
Pi DX[4] = {Pi(-1, 0), Pi(1, 0), Pi(0, -1), Pi(0, 1)};
char MAP[MAX_H][MAX_W + 1];
Pi ST, GL;

bool in_map(int i, int j) {
  return (0 <= i && i < W) && (0 <= j && j < W);
}

int dijkstra(int x) {
  ll d[MAX_H][MAX_W];
  std::priority_queue<Pli, vector<Pli>, greater<Pli> > pque;
  for (size_t i = 0; i < H; i++) fill(d[i], d[i] + W, INF);
  d[ST.first][ST.second] = 0;
  pque.push(Pli(0, ST));
  while (!pque.empty()) {
    Pli pli = pque.top(); pque.pop();
    Pi p = pli.second;
    if (p == GL) break;
    ll c = d[p.first][p.second];
    if (c < pli.first) continue;
    for (size_t i = 0; i < 4; i++) {
      Pi q = Pi(p.first + DX[i].first, p.second + DX[i].second);
      if (in_map(q.first, q.second)) {
        int cost = (MAP[q.first][q.second] == '#')? x: 1;
        if (d[p.first][p.second] + cost < d[q.first][q.second]) {
          d[q.first][q.second] = d[p.first][p.second] + cost;
          pque.push(Pli(d[q.first][q.second], q));
        }
      }
    }
  }
  return d[GL.first][GL.second];
}

void solve() {
  ll xl = 1, xr = T;
  while (xr - xl > 1) {
    ll xm = (xl + xr) / 2;
//    printf("%lld %lld %lld\n", xl, xm, xr);
    if (dijkstra(xm) <= T) {
      xl = xm;
    } else {
      xr = xm;
    }
  }
  printf("%lld\n", xl);
}

int main() {
  scanf("%d %d %lld", &H, &W, &T);
  for (size_t i = 0; i < H; i++) {
    scanf("%s", MAP[i]);
    for (size_t j = 0; j < W; j++) {
      if (MAP[i][j] == 'S') {
        MAP[i][j] = '.';
        ST = Pi(i, j);
      } else if (MAP[i][j] == 'G') {
        MAP[i][j] = '.';
        GL = Pi(i, j);
      }
    }
  }

  solve();

  return 0;
}

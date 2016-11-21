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

#define INF   (1e9+7)
#define MAX_V (200)
#define MAX_E (10000)
#define MAX_R (1000)
#define MAX_C (1000)

struct edge { int to; int cost; char type; };
struct Postman { int pos; int ship; int cost; };
int V, E, R;
std::vector<edge> G[MAX_V];
int D[MAX_V][MAX_V], PATH[MAX_R];

bool cmp(const Postman &p1, const Postman &p2) {
  return p1.cost < p2.cost;
}

void solve() {
  for (size_t v = 0; v < V; v++) fill(D[v], D[v] + V, INF);
  D[PATH[0]][PATH[0]] = 0;

  for (size_t i = 0; i < R - 1; i++) {
    std::priority_queue<Postman, vector<Postman>, function<bool(Postman, Postman)> > pque(cmp);
    int v0 = PATH[i], vf = PATH[i + 1];
    for (int s = 0; s < V; s++) {
      if (D[v0][s] < INF) pque.push((Postman) {v0, s, D[v0][s]});
    }
    while (!pque.empty()) {
      Postman p = pque.top(); pque.pop();
      int v = p.pos, s = p.ship;
      if(D[v][s] < p.cost) continue;
      for (size_t j = 0; j < G[v].size(); j++) {
        edge e = G[v][j];
        int u = e.to, cost = e.cost;
        if (e.type == 'L') {
          if (D[v][s] + cost < D[u][s]) {
            D[u][s] = D[v][s] + cost;
            if (u != vf) pque.push((Postman) {u, s, D[u][s]});
          }
        } else if (v == s) {
          if (D[v][s] + cost < D[u][u]) {
            D[u][u] = D[v][s] + cost;
            if (u != vf) pque.push((Postman) {u, u, D[u][u]});
          }
        }
      }
    }
    for (size_t v = 0; v < V; v++) {
      if (v != vf) fill(D[v], D[v] + V, INF);
    }
  }

  int vF = PATH[R - 1];
  int ans = INF;
  for (size_t s = 0; s < V; s++) {
    ans = min(ans, D[vF][s]);
  }
  printf("%d\n", ans);
}

int main() {
  while (true) {
    scanf("%d %d", &V, &E);
    if (V == 0) break;
    for (size_t i = 0; i < E; i++) {
      int v, u, cost;
      char c;
      scanf("%d %d %d %c\n", &v, &u, &cost, &c);
      v--; u--;
      G[v].push_back((edge) {u, cost, c});
      G[u].push_back((edge) {v, cost, c});
    }
    scanf("%d", &R);
    for (size_t i = 0; i < R; i++) {
      scanf("%d", &PATH[i]);
      PATH[i]--;
    }

    solve();
  }

  return 0;
}

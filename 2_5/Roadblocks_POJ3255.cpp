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

typedef struct{int to; int cost;} edge;

#define INF   (1e9+7)
#define MAX_N (5000)
#define MAX_R (100000)

int N, R;
std::vector<edge> G[MAX_N];
int D[MAX_N];
int D2[MAX_N];

void dijkstra(int s) {
  std::priority_queue<Pi, vector<Pi>, greater<Pi> > pque;
  fill(D, D + N, INF); fill(D2, D2 + N, INF);
  D[s] = 0;
  pque.push(Pi(0, s));
  while (!pque.empty()) {
    Pi p = pque.top(); pque.pop();
    int dv = p.first, v = p.second;
    if (D2[v] < dv) continue;
    for (size_t i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      int u = e.to, c = e.cost;
      int du = dv + c;
      if (du < D[u]) {
        // printf("D[%d] : %d -> %d\n", u, D[u], du);
        // printf("D2[%d]: %d -> %d\n", u, D2[u], D[u]);
        D2[u] = D[u];
        D[u] = du;
        pque.push(Pi(du, u));
      } else if (du < D2[u]) {
        // printf("D2[%d]: %d -> %d\n", u, D2[u], du);
        D2[u] = du;
        pque.push(Pi(du, u));
      }
    }
  }
}

void solve() {
  dijkstra(0);
  printf("%d\n", D2[N - 1]);
}

int main() {
  scanf("%d %d", &N, &R);
  for (size_t i = 0; i < R; i++) {
    int v, u, cost;
    scanf("%d %d %d", &v, &u, &cost);
    v--; u--;
    G[v].push_back((edge) {u, cost});
    G[u].push_back((edge) {v, cost});
  }

  solve();

  return 0;
}

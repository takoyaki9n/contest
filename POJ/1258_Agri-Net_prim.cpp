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

#define INF   (1e9 + 7)
#define MAX_V (100)

int V;
int COST[MAX_V][MAX_V], MINCOST[MAX_V];

int prim() {
  fill(MINCOST, MINCOST + V, INF);
  std::priority_queue<Pi, vector<Pi>, greater<Pi> > pque;
  MINCOST[0] = 0;
  pque.push(Pi(0, 0));
  int res = 0;
  while (!pque.empty()) {
    Pi pr = pque.top(); pque.pop();
    int v = pr.second, c = pr.first;

    if (MINCOST[v] < c) continue;

    res += c;

    for (size_t u = 0; u < V; u++) {
      if (COST[v][u] < MINCOST[u]) {
        MINCOST[u] = COST[v][u];
        pque.push(Pi(COST[v][u], u));
      }
    }
  }
  return res;
}

void solve() {
  int ans = prim();

  printf("%d\n", ans);
}

int main() {
  while(scanf("%d", &V) != EOF){
    for (size_t i = 0; i < V; i++) {
      for (size_t j = 0; j < V; j++) {
        scanf("%d", &COST[i][j]);
      }
    }

    solve();
  }

  return 0;
}

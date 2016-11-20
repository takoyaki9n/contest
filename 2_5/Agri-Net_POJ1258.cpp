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
bool USED[MAX_V];

int prim() {
  fill(MINCOST, MINCOST + V, INF);
  fill(USED, USED + V, false);
  MINCOST[0] = 0;
  int res = 0;
  while (true) {
    int v = -1;
    for (size_t u = 0; u < V; u++) {
      if (!USED[u] && (v == -1 || MINCOST[u] < MINCOST[v])) v = u;
    }
    if (v == -1) break;
    USED[v] = true;
    res += MINCOST[v];

    for (size_t u = 0; u < V; u++) {
      MINCOST[u] = min(MINCOST[u], COST[v][u]);
    }
  }
  return res;
}

void solve() {
  int ans = prim();

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &V);
  for (size_t i = 0; i < V; i++) {
    for (size_t j = 0; j < V; j++) {
      scanf("%d", &COST[i][j]);
    }
  }

  solve();

  return 0;
}

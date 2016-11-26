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
#define MAX_V (10)
#define MAX_E (45)
#define MAX_C (100)

int V, E;
int D[MAX_V][MAX_V];

void warshall_floyd() {
  for (size_t w = 0; w < V; w++)
    for (size_t u = 0; u < V; u++)
      for (size_t v = 0; v < V; v++) D[u][v] = min(D[u][v], D[u][w] + D[w][v]);
}

void solve() {
  int ans_c, ans_d = INF;

  warshall_floyd();

  for (size_t v = 0; v < V; v++) {
    int cost = 0;
    for (size_t u = 0; u < V; u++) cost += (D[u][v] < INF)? D[u][v]: 0;
    if (cost < ans_d) {
      ans_c = v;
      ans_d = cost;
    }
  }

  printf("%d %d\n", ans_c, ans_d);
}

int main() {
  while (true) {
    scanf("%d", &E);
    if (E == 0) break;

    for (size_t u = 0; u < MAX_V; u++)
      for (size_t v = 0; v < MAX_V; v++) D[u][v] = (u == v)? 0: INF;

    V = 0;
    for (size_t i = 0; i < E; i++) {
      int v, u, cost;
      scanf("%d %d %d", &u, &v, &cost);
      D[u][v] = D[v][u] = cost;
      V = max(V, (max(u, v)));
    }
    V++;

    solve();
  }

  return 0;
}

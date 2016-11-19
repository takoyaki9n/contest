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
#define MAX_V (5000)
#define MAX_E (MAX_V * (MAX_V - 1) /2)

int V, E;
std::vector<edge> G[MAX_V];
int d[MAX_V];

bool bellman_ford(int s) {
  fill(d, d + V, INF);
  d[s] = 0;
  for (size_t l = 0; l < V; l++) {
    bool update = false;
    for (size_t v = 0; v < V; v++) {
      for (size_t i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        if (d[v] != INF && d[e.to] > d[v] + e.cost) {
          d[e.to] = d[v] + e.cost;
          update = true;
          if (l == V - 1) return true;
        }
      }
    }
    if (!update) break;
  }
  return false;
}

void solve() {
  int ans = 0;

  printf("%d\n", ans);
}

int main() {
  scanf("%d %d", &V, &E);

  solve();

  return 0;
}

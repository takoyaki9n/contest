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

int V, E;
std::vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  std::priority_queue<Pi, vector<Pi>, greater<Pi>> pque;
  fill(d, d + V, INF);
  d[s] = 0;
  pque.push(Pi(0, s));
  while (!pque.empty()) {
    Pi p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.second) continue;
    for (size_t i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pque.push(Pi(d[e.to], e.to));
      }
    }
  }
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

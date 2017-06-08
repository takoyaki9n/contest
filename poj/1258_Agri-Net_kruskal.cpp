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

typedef struct{int from; int to; int cost;} edge;

#define INF   (1e9 + 7)
#define MAX_V (100)
#define MAX_E (MAX_V * (MAX_V - 1) >> 1)

int V, E;
edge EDGES[MAX_E];
int PAR[MAX_V], RNK[MAX_V];

bool cmp(const edge &e1, const edge &e2) {
  return e1.cost < e2.cost;
}

void init_union_find(int n) {
  for (size_t i = 0; i < n; i++) {
    PAR[i] = i;
    RNK[i] = 0;
  }
}

int find(int x) {
  if (PAR[x] == x) {
    return x;
  } else {
    return RNK[x] = find(PAR[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (RNK[x] < RNK[y]){
    PAR[x] = y;
  } else {
    PAR[y] = x;
    if (RNK[x] == RNK[y]) RNK[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int kruskal() {
  sort(EDGES, EDGES + E, cmp);
  init_union_find(V);
  int res = 0;
  for (size_t i = 0; i < E; i++) {
    edge e = EDGES[i];
//    printf("%d-%d(%d)\n", e.from, e.to, e.cost);
    if (!same(e.from, e.to)) {
      unite(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}

void solve() {
  int ans = kruskal();

  printf("%d\n", ans);
}

int main() {
  while(scanf("%d", &V) != EOF){
    E = 0;
    for (size_t i = 0; i < V; i++) {
      for (size_t j = 0; j < V; j++) {
        int cost;
        scanf("%d", &cost);
        if (i < j) {
          EDGES[E++] = (edge) {i, j, cost};
        }
      }
    }

    solve();
  }

  return 0;
}

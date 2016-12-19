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
#define MAX_N (200000)
#define MAX_K (100000)
#define MAX_L (100000)

class UnionFind {
private:
  int par[MAX_N];
public:
  void init(int n) {
    for (int x = 0; x < n; x++) par[x] = x;
  }
  int find(int x) {
    return (par[x] == x)? x: par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) par[y] = x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int N, K, L;
std::vector<int> GR[MAX_N], GT[MAX_N];
UnionFind UFR, UFT;
map<Pi, int> COUNTS;

void mapping(vector<int> *g, UnionFind &uf) {
  uf.init(N);
  for (int v = 0; v < N; v++) {
    if (uf.find(v) != v) continue;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < g[u].size(); i++) {
        int w = g[u][i];
        if (!uf.same(v, w)) {
          uf.unite(v, w);
          q.push(w);
        }
      }
    }
  }
}

void solve() {
  mapping(GR, UFR);
  mapping(GT, UFT);
  for (int v = 0; v < N; v++){
    Pi p = Pi(UFR.find(v), UFT.find(v));
    COUNTS[p] = COUNTS[p] + 1;
  }
  for (int v = 0; v < N; v++) {
    printf("%d ", COUNTS[Pi(UFR.find(v), UFT.find(v))]);
  }
  printf("\n");
}

int main() {
  scanf("%d %d %d", &N, &K, &L);
  for (int i = 0; i < K; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    GR[u].push_back(v);
    GR[v].push_back(u);
  }
  for (int i = 0; i < L; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    GT[u].push_back(v);
    GT[v].push_back(u);
  }


  solve();

  return 0;
}

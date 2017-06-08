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

struct Postman { int pos; int ship; int cost; };

int V, E, R;
int DL[MAX_V][MAX_V], DS[MAX_V][MAX_V], DP[MAX_R][MAX_V], PATH[MAX_R];

void warshall_floyd(int d[][MAX_V]) {
  for (size_t w = 0; w < V; w++)
    for (size_t u = 0; u < V; u++)
      for (size_t v = 0; v < V; v++) d[u][v] = min(d[u][v], d[u][w] + d[w][v]);
}

void solve() {
  warshall_floyd(DL);
  warshall_floyd(DS);

  for (size_t i = 0; i < R; i++)
    for (size_t v = 0; v < V; v++) DP[i][v] = INF;
  DP[0][PATH[0]] = 0;

  for (size_t i = 1; i < R; i++) {
    int u = PATH[i - 1], v = PATH[i];
    for (int w = 0; w < V; w++) {
      for (int x = 0; x < V; x++) {
//        printf("DP[%d][%d]+DL[%d][%d]+DS[%d][%d]+DL[%d][%d] = %d\n",i-1,w,u,w,w,x,x,v,d);
        int d = DP[i-1][w];
        d += (w == x)? DL[u][v]: DL[u][w] + DS[w][x] + DL[x][v];
        DP[i][x] = (0 <= d)? min(DP[i][x], d): DP[i][x];
      }
    }
  }

  int ans = INF;
  for (size_t v = 0; v < V; v++) ans = min(ans, DP[R-1][v]);
  printf("%d\n", ans);
}

int main() {
  while (true) {
    scanf("%d %d", &V, &E);
    if (V == 0) break;
    for (size_t v = 0; v < V; v++)
      for (size_t u = 0; u < V; u++) DL[v][u] = DS[v][u] = (u == v)? 0: INF;

    for (size_t i = 0; i < E; i++) {
      int v, u, cost; char c;
      scanf("%d %d %d %c\n", &v, &u, &cost, &c);
      v--; u--;
      if (c == 'L') {
        DL[u][v] = DL[v][u] = min(DL[u][v], cost);
      } else {
        DS[u][v] = DS[v][u] = min(DS[u][v], cost);
      }
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

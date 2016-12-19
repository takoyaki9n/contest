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

int N, K, L;
std::vector<int> GR[MAX_N];
std::vector<int> GT[MAX_N];
bool TABLE_R[MAX_N], TABLE_T[MAX_N];

void mapping(int s, vector<int> *g, bool *tbl) {
  fill(tbl, tbl + N, false);
  queue<int> que;
  tbl[s] = true;
  que.push(s);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i];
      if (!tbl[u]) {
        tbl[u] = true;
        que.push(u);
      }
    }
  }
}

void solve() {
  for (int v = 0; v < N; v++) {
    mapping(v, GR, TABLE_R);
    mapping(v, GT, TABLE_T);
    int ans = 0;

    // printf("%d: ", v);
    // for (int u = 0; u < N; u++) {
    //   if (TABLE_R[u])
    //     printf("%s", (TABLE_T[u])? "B ": "R ");
    //   else 
    //     printf("%s", (TABLE_T[u])? "T ": "N ");
    // }
    // printf("\n");

    for (int u = 0; u < N; u++) {
      if (TABLE_R[u] && TABLE_T[u]) ans++;
    }
    printf("%d ", ans);    
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

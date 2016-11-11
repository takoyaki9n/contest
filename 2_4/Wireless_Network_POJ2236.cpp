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
typedef set<int> Si;

#define INF   (1e9 + 7)
#define MAX_N (1001)
#define MAX_D (20000)
#define MAX_XY (10000)

int N, D2;
int P[MAX_N][2];
Si G[MAX_N];

int par[MAX_N], rnk[MAX_N];

void init(int n) {
  for (size_t i = 0; i < n; i++) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

void solve() {
  char c;
  int n, m;
  Si act;
  init(N);
  while(scanf("\n%c", &c) != EOF){
    if (c == 'O') {
      scanf("%d", &n);
      n--;
      for (set<int>::iterator it = act.begin(); it != act.end(); it++) {
        int m = *it;
        if (G[n].find(m) != G[n].end()) {
          unite(n, m);
        }
     }
      act.insert(n);
    } else if(c == 'S'){
      scanf("%d %d", &n, &m);
      n--; m--;
      if (same(n, m)) {
        printf("SUCCESS\n");
      } else {
        printf("FAIL\n");
      }
    } else {
      printf("Unknown %c\n", c);
    }
  }
}

int main() {
  scanf("%d %d", &N, &D2);
  D2 = D2 * D2;
  for (size_t i = 0; i < N; i++) {
    scanf("%d %d", &P[i][0], &P[i][1]);
    for (size_t j = 0; j < i; j++) {
      int dx = P[i][0] - P[j][0];
      int dy = P[i][1] - P[j][1];
      if (dx * dx + dy * dy <= D2) {
        G[i].insert(j);
        G[j].insert(i);
      }
    }
  }

  solve();

  return 0;
}

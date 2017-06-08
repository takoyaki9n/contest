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
bool G[MAX_N][MAX_N];
int par[MAX_N], rnk[MAX_N];
int ACT[MAX_N];

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
  init(N);
  int i = 0;
  while(scanf("\n%c", &c) != EOF){
    if (c == 'O') {
      int n;
      scanf("%d", &n); n--;
      for (size_t j = 0; j < i; j++) {
        int m = ACT[j];
        if (G[n][m]) {
          unite(n, m);
        }
      }
      ACT[i] = n; i++;
    } else if(c == 'S'){
      int n, m;
      scanf("%d %d", &n, &m); n--; m--;
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

  for (size_t i = 0; i < N; i++)
    for (size_t j = 0; j < N; j++)
      G[i][j] = false;

  for (size_t i = 0; i < N; i++) {
    scanf("%d %d", &par[i], &rnk[i]);
    for (size_t j = 0; j < i; j++) {
      int dx = par[i] - par[j];
      int dy = rnk[i] - rnk[j];
      if (dx * dx + dy * dy <= D2) {
        G[i][j] = true;
        G[j][i] = true;
      }
    }
  }

  solve();

  return 0;
}

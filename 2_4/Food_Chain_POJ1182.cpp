#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (50000)
#define MAX_K (100000)

int par[3 * MAX_N], rnk[3 * MAX_N];
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void init(int par[], int rnk[], int n) {
  for (size_t i = 0; i < n; i++) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x, int par[], int rnk[]) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x], par, rnk);
  }
}

void unite(int x, int y, int par[], int rnk[]) {
  x = find(x, par, rnk);
  y = find(y, par, rnk);
  if (x == y) return;
  if (rnk[x] < rnk[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y, int par[], int rnk[]) {
  return find(x, par, rnk) == find(y, par, rnk);
}

void solve() {
  int ans = 0;

  init(par, rnk, 3 * N);

  for (size_t i = 0; i < K; i++) {
    int t = T[i];
    int x = X[i] - 1, y = Y[i] - 1;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++; continue;
    }
    if (t == 1) {
      if (same(x, y + N, par, rnk) || same(x, y + 2 * N, par, rnk)) {
        ans++;
      } else {
        unite(x, y, par, rnk);
        unite(x + N, y + N, par, rnk);
        unite(x + 2 * N, y + 2 * N, par, rnk);
      }
    } else {
      if (same(x, y, par, rnk) || same(x, y + 2 * N, par, rnk)) {
        ans++;
      } else {
        unite(x, y + N, par, rnk);
        unite(x + N, y + 2 * N, par, rnk);
        unite(x + 2 * N, y, par, rnk);
      }
    }
  }

  std::cout << ans << std::endl;
}

int main() {
  std::cin >> N >> K;
  for (size_t i = 0; i < K; i++) {
    std::cin >> T[i] >> X[i] >> Y[i];
  }

  solve();

  return 0;
}

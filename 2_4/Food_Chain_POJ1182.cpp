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
  int ans = 0;

  init(3 * N);

  for (size_t i = 0; i < K; i++) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--; y--;

    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++; continue;
    }
    if (t == 1) {
      if (same(x, y + N) || same(x, y + 2 * N)) {
        ans++;
      } else {
        unite(x, y);
        unite(x + N, y + N);
        unite(x + 2 * N, y + 2 * N);
      }
    } else {
      if (same(x, y) || same(x, y + 2 * N)) {
        ans++;
      } else {
        unite(x, y + N);
        unite(x + N, y + 2 * N);
        unite(x + 2 * N, y);
      }
    }
  }

  std::cout << ans << std::endl;
}

int main() {
  std::cin >> N >> K;

  solve();

  return 0;
}

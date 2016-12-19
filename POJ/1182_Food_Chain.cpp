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

class UnionFind {
private:
  int par[MAX_N * 3];
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

int N, K;
UnionFind UF;

void solve() {
  int ans = 0;

  UF.init(3 * N);

  for (size_t i = 0; i < K; i++) {
    int t, x, y;
    scanf("%d %d %d", &t, &x, &y);
    x--; y--;

    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++; continue;
    }
    if (t == 1) {
      if (UF.same(x, y + N) || UF.same(x, y + 2 * N)) {
        ans++;
      } else {
        UF.unite(x, y);
        UF.unite(x + N, y + N);
        UF.unite(x + 2 * N, y + 2 * N);
      }
    } else {
      if (UF.same(x, y) || UF.same(x, y + 2 * N)) {
        ans++;
      } else {
        UF.unite(x, y + N);
        UF.unite(x + N, y + 2 * N);
        UF.unite(x + 2 * N, y);
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

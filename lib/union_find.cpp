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

int PAR[MAX_N], RNK[MAX_N];
int N, K;

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

int main() {
  std::cin >> N >> K;

  return 0;
}

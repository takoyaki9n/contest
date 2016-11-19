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

int main() {
  std::cin >> N >> K;

  return 0;
}

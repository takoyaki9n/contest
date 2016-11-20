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

void init_union_find(int n) {
  for (size_t i = 0; i < n; i++) {
    PAR[i] = i;
    RNK[i] = 0;
  }
}

int find(int x) {
  if (PAR[x] == x) {
    return x;
  } else {
    return RNK[x] = find(PAR[x]);
  }
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (RNK[x] < RNK[y]){
    PAR[x] = y;
  } else {
    PAR[y] = x;
    if (RNK[x] == RNK[y]) RNK[x]++;
  }
}

bool same(int x, int y) {
  return find(x) == find(y);
}

int main() {
  std::cin >> N >> K;

  return 0;
}

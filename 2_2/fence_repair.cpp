#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (20000)
#define MAX_X (50000)
#define INF    (MAX_N * MAX_X + 1)

int N;
int X[MAX_N];

void print_array(int *ar, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

void insert_heap(int *hp, int x, int n) {
  hp[n] = x;
  while (n > 0) {
    int m = (n - 1) >> 1;
    if (x >= hp[m]) { break; }
    hp[n] = hp[m]; hp[m] = x; n = m;
  }
}

void deltop_heap(int *hp, int n) {
  int m = 0;
  hp[m] = hp[n-1];
  while (m < n - 1) {
    int l = (m << 1) + 1; int r = (m + 1) << 1;
    int xl = (l < n - 1) ? hp[l]: INF;
    int xr = (r < n - 1) ? hp[r]: INF;
    if (hp[m] <= xl && hp[m] <= xr) { break; }
    if (xl < xr) {
      if (xl < hp[m]) {
        hp[l] = hp[m]; hp[m] = xl; m = l;
      }
    } else {
      if (xr < hp[m]) {
        hp[r] = hp[m]; hp[m] = xr; m = r;
      }
    }
  }
}

int main() {
  scanf("%d\n", &N);
  for (size_t i = 0; i < N; i++) {
    int x;
    scanf("%d\n", &x);
    insert_heap(X, x, i);
  }

  ll cost = 0;
  for (size_t i = N; i > 1; i--) {
    int t = X[0];
    deltop_heap(X, i);
    t += X[0];
    deltop_heap(X, i - 1);
    cost += t;
    insert_heap(X, t, i - 2);
  }

  printf("%lld\n", cost);
  return 0;
}

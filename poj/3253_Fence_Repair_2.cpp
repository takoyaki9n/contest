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

int main() {
  scanf("%d\n", &N);
  for (size_t i = 0; i < N; i++) {
    scanf("%d\n", &X[i]);
  }

  ll cost = 0;
  while (N > 1) {
    int mii1 = 0, mii2 = 1;
    if (X[mii1] > X[mii2]) { swap(mii1, mii2); }
    for (size_t i = 2; i < N; i++) {
      if (X[i] < X[mii1]) {
        mii2 = mii1; mii1 = i;
      } else if (X[i] < X[mii2]) {
        mii2 = i;
      }
    }

    int t = X[mii1] + X[mii2];
    cost += t;

    if (mii1 == N - 1) { swap(mii1, mii2); }
    printf("%d\n", t);

    X[mii1] = t;
    X[mii2] = X[N-1];
    N--;
  }

  printf("%lld\n", cost);
  return 0;
}

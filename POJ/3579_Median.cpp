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

#define INF   (1e9 + 7)
#define MAX_N (100000)
#define MAX_X (1000000000)

ll N, M, MID;
int X[MAX_N + 1];

ll count_lt(int v) {
  ll cnt = 0;
  for (int i = 0; i < N - 1; i++) {
    cnt += (int) (lower_bound(X + i + 1, X + N, X[i] + v) - (X + i + 1));
  }
  // printf("cnt = %lld\n", cnt);
  return cnt;
}

void solve() {
  sort(X, X + N);

  // for (int i = 0; i < N; i++) printf("%d ", X[i]);
  // printf("\n");
  // printf("MID = %lld\n", MID);
  
  int vl = 0, vr = X[N - 1];
  while (vr - vl > 1) {
    int vm = (vl + vr) / 2;
    // printf("%d %d %d\n", vl, vm, vr);
    if (count_lt(vm) < MID) {
      vl = vm;
    } else {
      vr = vm;
    }
  }

  printf("%d\n", vl);
}

int main() {
  while (scanf("%lld", &N) != EOF) {
    M = (N - 1) * N / 2;
    MID = (M + 1) / 2;
    for (int i = 0; i < N; i++) scanf("%d", &X[i]);
    
    solve();
  }

  return 0;
}

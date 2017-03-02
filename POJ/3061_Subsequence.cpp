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

//#define DEBUG
#ifdef DEBUG
#define dprintf printf
#else
#define dprintf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define INF   (1e9 + 7)
#define MAX_N (100000)
#define MAX_S (100000000)
#define MAX_A (10000)

int N, S, T;
int SUM[MAX_N + 1];

void solve() {
  debug_printf("%d\n", 22);
  int ans = INF;

  if (SUM[N] - SUM[0] < S) {
    ans = 0;
  } else {
    for (int i = 0; i < N; i++) {
      if (SUM[N] - SUM[i] < S) continue;

      int xl = i, xr = N;
      while (xr - xl > 1) {
        int xm = (xl + xr) / 2;
        int sum = SUM[xm] - SUM[i];
        if (sum < S) {
          xl = xm;
        } else {
          xr = xm;
        }
      }

      ans = min(ans, xr - i);
    }
  }

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d %d", &N, &S);
    SUM[0] = 0;
    for (int j = 0; j < N; j++) {
      int a;
      scanf("%d", &a);
      SUM[j + 1] = SUM[j] + a;
    }
    solve();
  }
  return 0;
}

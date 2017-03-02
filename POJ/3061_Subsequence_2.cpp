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
int A[MAX_N];

void solve() {
  int ans = N + 1;
  
  int s, t, sum;
  s = t = sum = 0;
  while (s < N) {
    while (t <= N) {
      dprintf("sum[%d:%d] = %d\n", s, t, sum);
      if (sum >= S) {
        dprintf("t - s = %d\n", t - s);
        ans = min(ans, t - s);
        break;
      }
      sum += A[t++];
    }
    sum -= A[s++];
  }

  ans = (ans < N)? ans: 0;

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%d %d", &N, &S);
    for (int j = 0; j < N; j++) scanf("%d", &A[j]);

    solve();
  }
  return 0;
}

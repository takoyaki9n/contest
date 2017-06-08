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

#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define FST first
#define SND second

#define MAX_N   (5000)                  // 10^4
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
int A[MAX_N], DP[MAX_N + 1];
map<int, int> L, R;

int solve() {
  DP[0] = 0;
  for (int i = 0; i < N; i++) {
    if (L.count(A[i]) == 0) L[A[i]] = i;
    R[A[i]] = i;
    DP[i + 1] = -1;
  }

  for (int i = 0; i < N; i++) {
    int a = A[i];
    int l = L[a], r = R[a], v = DP[i];
    if (i == r) {
      int x = 0;
      bool close = true;
      for (int j = r; j >= l; j--) {
        int b = A[j];
        int lb = L[b], rb = R[b];
        if (r < rb) {
          close = false;
          break;
        }
        if (j == rb) x ^= b;
        l = min(l, lb);
      }
      if (close) {
        v = max(v, DP[l] + x);
      }
    }
    DP[i + 1] = v;
  }

  return DP[N];
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  cout << solve() << endl;

  return 0;
}

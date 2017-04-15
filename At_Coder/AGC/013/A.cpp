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
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define INF   (1e9 + 7)
#define MAX_N (100000)

int N;
int A[MAX_N];

void solve() {
  int ans = 1;
  int x = A[0], y = A[0];
  for (int i = 1; i < N; i++) {
    if (A[i] == x) continue;
    int s = (A[i] - x) / abs(A[i] - x);
    if (s * (x - y) < 0) {
      ans++;
      y = x = A[i];
    } else {
      y = x; x = A[i];
    }
  }

  printf("%d\n", ans);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  solve();

  return 0;
}

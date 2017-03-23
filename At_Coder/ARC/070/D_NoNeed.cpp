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
#define MAX_N (5000)
#define MAX_K (5000)

int N, K;
int A[MAX_N];
bool DP[MAX_N + 1][MAX_K];

bool check(int x) {
  for (int i = 0; i <= N; i++) 
    for (int j = 0; j < K; j++) DP[i][j] = false;
  DP[0][0] = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      bool flag = DP[i][j];
      int k = j - A[i];
      if (i != x && k >= 0) flag |= DP[i][k];
      DP[i + 1][j] = flag;
    }
  }

  debug_printf("x = %d\n", x);
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < K; j++) debug_printf("%s ", DP[i][j]? "o": "x");
    debug_printf("\n");
  }
  debug_printf("\n");

  for (int k = max(0, K - A[x]); k < K; k++) 
    if (DP[N][k]) return true;
  
  return false;
}

void solve() {
  sort(A, A + N);
  
  int xl = -1, xr = N;    
  while (xr - xl > 1) {
    int xm = (xl + xr) / 2;
    if (check(xm)) {
      xr = xm;
    } else {
      xl = xm;
    }
  }  

  printf("%d\n", xr);
}

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);

  solve();

  return 0;
}

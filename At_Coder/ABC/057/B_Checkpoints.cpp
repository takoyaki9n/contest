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

#define INF   (1e9 + 7)
#define MAX_N (50)

int N, M;
int S[MAX_N][2], C[MAX_N][2];

void solve() {
  for (int i = 0; i < N; i++) {
    int a = S[i][0], b = S[i][1];
    int goal = -1, cost = INF;
    for (int j = 0; j < M; j++) {
      int c = C[j][0], d = C[j][1];
      int x = abs(a - c) + abs(b - d);
      if (x < cost) {
        cost = x;
        goal = j + 1;
      }
    }
    printf("%d\n", goal);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d %d", &S[i][0], &S[i][1]);
  for (int i = 0; i < M; i++) scanf("%d %d", &C[i][0], &C[i][1]);

  solve();

  return 0;
}

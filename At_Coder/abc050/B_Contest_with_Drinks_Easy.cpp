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
#define MAX_N (100)
#define MAX_M (100)

int N, M;
int T[MAX_N], P[MAX_M], X[MAX_M];
ll SUM;

void solve() {
  for (int i = 0; i < M; i++) {
    int ans = SUM - T[P[i]] + X[i];
    printf("%d\n", ans);
  }
}

int main() {
  SUM = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
    SUM += T[i];
  }
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &P[i], &X[i]);
    P[i]--;
  }

  solve();

  return 0;
}

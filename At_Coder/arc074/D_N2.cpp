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

#define MAX_N   (100000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
ll A[3 * MAX_N], B[3 * MAX_N];

void solveN2() {
  ll ans = -INFL;

  for (int i = 0; i <= N; i++) {
    for (int j = 0; j < 3 * N; j++) B[j] = A[j];
    sort(B, B + N + i);
    sort(B + N + i, B + 3 * N);
    ll score = 0;
    for (int j = i; j < N + i; j++) score += B[j];
    for (int j = N + i; j < 2 * N + i; j++) score -= B[j];
    ans = max(ans, score);
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < 3 * N; i++) cin >> A[i];

  solveN2();

  return 0;
}
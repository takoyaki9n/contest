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
ll A[3 * MAX_N], SUM[2][MAX_N + 1];

void solve() {
  priority_queue<ll, vector<ll>, greater<ll> > former;
  priority_queue<ll> latter;

  SUM[0][0] = SUM[1][N] = 0;
  for (int i = 0; i < N; i++) {
    SUM[0][0] += A[i];
    former.push(A[i]);
    SUM[1][N] += A[2 * N + i];
    latter.push(A[2 * N + i]);
  }

  for (int i = 0; i < N; i++) {
    ll a = A[N + i];
    former.push(a);
    SUM[0][i + 1] = SUM[0][i] - former.top() + a;
    former.pop();
    ll b = A[2 * N - 1 - i];
    latter.push(b);
    SUM[1][N - 1 - i] = SUM[1][N - i] - latter.top() + b;
    latter.pop();
  }

  ll ans = -INFL;
  for (int i = 0; i <= N; i++) {
    ans = max(ans, SUM[0][i] - SUM[1][i]);
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < 3 * N; i++) cin >> A[i];

  solve();

  return 0;
}

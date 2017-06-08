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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (100000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll N, K;
Pl A[MAX_N];

void solve() {
  sort(A, A + N);
//  for (int i = 1; i < N; i++) A[i] = Pl(A[i].FST, A[i].SND + A[i - 1].SND);
  for (int i = 1; i < N; i++) A[i].SND += A[i - 1].SND;

  int xl = -1, xr = N - 1;
  while (xr - xl > 1) {
    int xm = (xr + xl) / 2;
    if (K <= A[xm].SND) {
      xr = xm;
    } else {
      xl = xm;
    }
  }

  cout << A[xr].FST << endl;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i].FST >> A[i].SND;

  solve();

  return 0;
}

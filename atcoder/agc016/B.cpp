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

#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int N, A[MAX_N];

string judge() {
  int mx = -1, mn = INFI, p = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] > mx) {
      mx = A[i];
      p = 1;
    } else if (A[i] == mx) {
      p++;
    }
    mn = min(mn, A[i]);
  }

  if (mx - mn > 1) return "No";

  bool flag;
  if (mn == mx) {
    flag = mx == N - 1 || mx <= N / 2;
  } else {
    int q = N - p;
    flag = q < mx && 2 * (mx - q) <= p;
  }

  return flag? "Yes": "No";
}

void solve() {
  cout << judge() << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  solve();

  return 0;
}

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

#define MAX_N   (100)                  // 10^5
#define MAX_S   (100)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, S[MAX_N];

void solve() {
  ll sum = 0;
  for (int i = 0; i < N; i++) sum += S[i];

  ll ans = 0;
  if (sum % 10 != 0) {
    ans = sum;
  } else {
    sort(S, S + N);
    for (int i = 0; i < N; i++) {
      if (S[i] % 10 != 0) {
        ans = sum - S[i];
        break;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  solve();

  return 0;
}

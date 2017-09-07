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

// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int N;
string S1, S2;

void solve() {
  ll ans;
  int k;
  if (S1[0] == S2[0]) {
    ans = 3; k = 1;
  } else {
    ans = 6; k = 2;
  }
  for (int i = k; i < N; i++) {
    if (S1[i] == S2[i]) {
      if (S1[i - 1] == S2[i - 1]) {
        ans = (ans * 2) % BASE;
      }
    } else {
      if (S1[i - 1] == S2[i - 1]) {
        ans = (ans * 2) % BASE;
      } else {
        ans = (ans * 3) % BASE;
      }
      i++;
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> N;
  cin >> S1;
  cin >> S2;

  solve();

  return 0;
}

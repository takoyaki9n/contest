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
#define MAX_N (10000000)

ll N;

void solve() {
  int root = sqrt(N);
  debug_printf("%d %f\n", root, sqrt(N));
  for (ll i = root; i >= 1; i--) {
    if (N % i == 0) {
      ll x = log10(i) + 1;
      ll y = log10(N / i) + 1;
      printf("%lld\n", max(x, y));
      return;
    }
  }
}

int main() {
  scanf("%lld", &N);

  solve();

  return 0;
}

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
typedef pair<ll, ll> Pl;

#define MOD   (1000000000 + 7)
#define MAX_N (1000000000000000000)

ll N;
map<Pl, ll> MAP;

ll func(ll S, ll X) {
//  printf("%lld, %lld\n", S, X);
  if (S < 0) return 0;
  if (S < 1) return 1;
  Pl p = Pl(S, X);
  if (MAP[p] > 0) return MAP[p];
  ll val = func(S / 2, X / 2) % MOD;
  val = (val + func((S - 1) / 2, X / 2)) % MOD;
  if (S > 1) val = (val + func((S - 2) / 2, X / 2)) % MOD;
  return MAP[p] = val;
}

void solve() {
  printf("%lld\n", func(N, N));
}

int main() {
  scanf("%lld", &N);

  solve();

  return 0;
}

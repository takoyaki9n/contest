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

#define FST first
#define SND second

#define MAX_N   (1000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

ll N, T, K ,D;

ll no_additional_oven() {
  ll t = 0, x = 0;
  while (x < N) {
    t += T;
    x += K;
  }
  return t;
}

ll with_additional_oven() {
  ll t = 0, x = 0;
  while (true) {
    if (t > 0 && t % T == 0) x += K;
    if (t > D && (t - D) % T == 0) x += K;
    if (x >= N) break;
    t++;
  }
  return t;
}

int main() {
  cin >> N >> T >> K >> D;

  ll t0 = no_additional_oven();
  ll t1 = with_additional_oven();
  if (t1 < t0) {
    cout << "YES" <<endl;
  } else {
    cout << "NO" <<endl;
  }

  return 0;
}

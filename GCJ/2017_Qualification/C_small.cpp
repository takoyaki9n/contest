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
#define MAX_N (1000000000000000000 + 1)

int T;
ll N, K;

ll solve() {
  priority_queue<int> pq;

  pq.push(N);
  for (int k = 0; k < K - 1; k++) {
    int x = pq.top(); pq.pop();
    pq.push(x / 2);
    pq.push((x - 1) / 2);
  }

  return pq.top();
}

int main() {
  scanf("%d", &T);
  for (int n = 0; n < T; n++) {
    scanf("%lld %lld", &N, &K);
    ll ans = solve();
    printf("Case #%d: %lld %lld\n", n + 1, ans / 2, (ans - 1) / 2);
  }

  return 0;
}

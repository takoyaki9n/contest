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

#define INF   (1e9 + 7)
#define MAX_P (1000000)

int P, BOOK[MAX_P];

void solve() {
  int ans = P + 1;
  set<int> st;
  for (int i = 0; i < P; i++) st.insert(BOOK[i]);
  int n = st.size();

  int s = 0, t = 0, m = 0;
  map<int, int> mp;
  while (s < P) {
    while (t < P && m < n) {
      int x = BOOK[t++];
      if (mp[x]++ == 0) m++;
    }
    if (m < n) break;
    ans = min(ans, t - s);
    int y = BOOK[s++];
    if (--mp[y] == 0) m--;
  }

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &P);
  for (int i = 0; i < P; i++) {
    scanf("%d", &BOOK[i]);
  }

  solve();

  return 0;
}

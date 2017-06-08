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
#define MAX_K (1000)

int T;
char S[20];

ll solve(char *S) {
  int l = strlen(S);

  debug_printf("%s\n", S);
  int n = l;
  for (int i = l - 1; i > 0; i--) {
    if (S[i - 1] <= S[i]) continue;
    n = i;
    S[i - 1]--;
    S[i] = '9';
  }

  ll ans = 0;
  for (int i = 0; i < l; i++){
    int d = (i < n)? S[i] - '0': 9;
    ans = 10 * ans + d;
  }

  return ans;
}

int main() {
  scanf("%d", &T);
  for (int n = 0; n < T; n++) {
    scanf("%s", S);
    ll ans = solve(S);
    printf("Case #%d: %lld\n", n + 1, ans);
  }

  return 0;
}

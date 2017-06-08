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

int T, K;
char S[MAX_K + 1];

int solve(char *S, int K) {
  int ans = 0;
  int l = strlen(S);

  debug_printf("%s %d\n", S, K);
  for (int i = 0; i <= l - K; i++) {
    if (S[i] == '+') continue;
    ans++;
    for (int j = i; j < i + K ; j++) S[j] = (S[j] == '+')? '-': '+';
    debug_printf("%s\n", S);
  }

  for (int i = l - K + 1; i < l; i++)
    if (S[i] == '-') return -1;

  return ans;
}

int main() {
  scanf("%d", &T);
  for (int n = 0; n < T; n++) {
    scanf("%s %d", S, &K);
    int ans = solve(S, K);
    if (ans >= 0) {
      printf("Case #%d: %d\n", n + 1, ans);
    } else {
      printf("Case #%d: IMPOSSIBLE\n", n + 1);
    }
  }

  return 0;
}

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
#define MAX_N (100000)

int N;
char S[MAX_N + 1];

char guess(char x, char y, char a) {
  return (y == 'S') ^ (a == 'o') ^ (x == 'S') ? 'S': 'W';
}

void solve() {
  char prefs[4][3] = {"SS", "SW", "WS", "WW"};
  char ans[N + 1];
  for (int i = 0; i < 4; i++) {
    ans[0] = prefs[i][0]; ans[1] = prefs[i][1];
    for (int j = 2; j < N; j++) {
      ans[j] = guess(ans[j - 2], ans[j - 1], S[j - 1]);
    }
    bool valid = (ans[0] == guess(ans[N - 2], ans[N - 1], S[N - 1])) && (ans[1] == guess(ans[N - 1], ans[0], S[0]));
    if (valid) {
      ans[N] = '\0';
      printf("%s\n", ans);
      return;
    }
  }
  printf("-1\n");
}

int main() {
  scanf("%d", &N);
  scanf("%s", S);

  solve();

  return 0;
}

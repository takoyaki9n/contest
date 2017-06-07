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
#define MAX_N (50)

int N;
string S[MAX_N];
int COUNT[26];

void solve() {
  for (int i = 0; i < 26; i++) COUNT[i] = 1000;

  for (int i = 0; i < N; i++) {
    int cnt[26];
    for (int j = 0; j < 26; j++) cnt[j] = 0;
    for (int j = 0; j < S[i].size(); j++) cnt[S[i][j] - 'a']++;
    for (int j = 0; j < 26; j++) COUNT[j] = min(COUNT[j], cnt[j]);
    for (int j = 0; j < 26; j++) debug_printf("%d ", COUNT[j]);
    debug_printf("\n");
  }
  for (int j = 0; j < 26; j++) {
    for (int k = 0; k < COUNT[j]; k++) {
      printf("%c", j + 'a');
    }
  }
  printf("\n");
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) cin >> S[i];

  solve();

  return 0;
}

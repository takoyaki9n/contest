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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (1500)                  // 10^5
#define MAX_Q   (200000)
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, Q;
string S;
int SUM[26][MAX_N + 1];

void make_sum() {
  for (int i = 0; i < 26; i++) SUM[i][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) SUM[j][i + 1] = SUM[j][i];
    int c = S[i] - 'a';
    SUM[c][i + 1]++;
  }

#ifdef DEBUG
  for (int j = 0; j < 26; j++) {
    char c = 'a' + j;
    cout << c << ": ";
    for (int i = 0; i <= N; i++) cout << SUM[j][i] << " ";
    cout << endl;
  }
#endif
}

void solve() {
  int m; char d;
  cin >> m >> d;

  int c = (int) d - 'a';
  int l = 0, r = 0;
  int res = 0;
  while (true) {
    while (r <= N) {
      int ds = SUM[c][r] - SUM[c][l];
      int d = r - l;
      if (ds + m < d) break;
      res = max(res, d);
      r++;
    }
    if (r > N) break;
    l++;
  }

  cout << res << endl;
}

int main() {
  cin >> N;
  cin >> S;

  make_sum();

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    solve();
  }

  return 0;
}

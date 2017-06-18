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

#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

// const int MAX_N = 1000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int N, CNT[26];
string S;

void solve() {
  for (int i = 0; i < 26; i++) CNT[i] = 0;

  for (int i = 0; i < N; i++) {
    int c = S[i] - 'a';
    CNT[c]++;
  }

  int ans = N;
  for (int c = 0; c < 26; c++) {
    if (CNT[c] > 0) {
      char d = c + 'a';
      int l = 0, t = 0;
      for (int i = 0; i < N; i++) {
        if (S[i] == d) {
          t = max(t, i - l);
          l = i + 1;
        }
      }
      t = max(t, N - l);
      ans = min(ans, t);
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> S;
  N = S.size();

  solve();

  return 0;
}

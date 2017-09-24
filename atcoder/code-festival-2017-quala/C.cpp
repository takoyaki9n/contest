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

const int MAX_H = 100;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int H, W;
string M[MAX_H];
int CNT[26];

bool check() {
  if (H % 2 == 0 && W % 2 == 0) {
    for (int i = 0; i < 26; i++) {
      if (CNT[i] % 4 != 0) return false;
    }
    return true;
  } else if (H % 2 != 0 && W % 2 != 0) {
    int a = 0, b = 0;
    for (int i = 0; i < 26; i++) {
      if (CNT[i] % 4 == 1) b++;
      else if (CNT[i] % 4 == 2) a++;
      else if (CNT[i] % 4 == 3) { a++; b++; }
    }
    if (b != 1) return false;
    return (2 * a <= H + W - 2);
  } else {
    int a = 0;
    for (int i = 0; i < 26; i++) {
      if (CNT[i] % 2 != 0) return false;
      if (CNT[i] % 4 != 0) a++;
    }
    if (H % 2 == 0) {
      return (2 * a <= H);
    } else {
      return (2 * a <= W);
    }
  }
}

void solve() {
  for (int i = 0; i < 26; i++) CNT[i] = 0;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int c = (int) (M[i][j] - 'a');
      CNT[c]++;
    }
  }

  if (check()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  cin >> H >> W;
  for (int i = 0; i < H; i++) cin >> M[i];

  solve();

  return 0;
}

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

const int MAX_H = 500;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int H, W, R, C;
int S[MAX_H + 1];

bool judge() {
  if (H % R == 0 && W % C == 0) return false;

  int n = (W % C == 0)? H: W;
  int k = (W % C == 0)? R: C;

  memset(S, 0, sizeof(S));

  S[n] = 1;
  for (int i = 0; i < n / k; i++) {
    int y = n - i * k;
    S[y - k] = S[y] + 1;
  }

  for (int i = 0; i < n - k; i++) {
    if (S[i] == 0) {
      for (int j = i; j + k < n; j += k) S[j + k] = S[j] - 1;
    }
  }

  return true;
}

void solve() {
  if (judge()) {
    cout << "Yes" << endl;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        int x = (W % C == 0)? i: j;
        cout << S[x + 1] - S[x] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}

int main() {
  cin >> H >> W >> R >> C;

  solve();

  return 0;
}

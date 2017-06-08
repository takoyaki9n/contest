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

#define FST first
#define SND second

#define MAX_N   (10000)                  // 10^4
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, M;
int P[MAX_N];

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> P[i];
  for (int i = 0; i < M; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--; x--;
    int cnt = 0;
    for (int i = l; i < r; i++) cnt += (P[i] < P[x]);

    string ans = (x - l == cnt)? "Yes": "No";
    cout << ans << endl;
  }

  return 0;
}

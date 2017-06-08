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
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (100)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, K;
int A[MAX_N], B[MAX_N];

bool check() {
  int z = -1;
  for (int i = 0; i < N; i++) {
    if (A[i] == 0) {
      if (z < 0) {
        z = i;
      } else {
        return true;
      }
    }
  }

  if (z >= 0) A[z] = B[0];

  for (int i = 1; i < N; i++) {
    if (A[i] <= A[i - 1]) return true;
  }

  return false;
}

void solve() {
  if (check()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < K; i++) cin >> B[i];

  solve();

  return 0;
}

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

#define FST first
#define SND second

#define MAX_N   (200000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, M;
int P[MAX_N], A[MAX_N], B[MAX_N];

void solve() {
  vector<int> stock[3];
  for (int i = 0; i < N; i++) {
    int a = A[i] - 1;
    int b = B[i] - 1;
    stock[a].push_back(P[i]);
    if (a != b) stock[b].push_back(P[i]);
  }
  for (int i = 0; i < 3; i++) sort(stock[i].begin(), stock[i].end());

  set<int> bought;
  int idx[3] = {0, 0, 0};
  cin >> M;
  for (int j = 0; j < M; j++) {
    int c; cin >> c; c--;
    while (true) {
      if (idx[c] >= stock[c].size()) {
        cout << -1 << " ";
        break;
      }
      int price = stock[c][idx[c]];
      if (bought.find(price) == bought.end()) {
        cout << price << " ";
        bought.insert(price);
        break;
      }
      idx[c]++;
    }
  }
  cout << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i];
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  solve();

  return 0;
}

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
#define MAX_N (100000)

int N, M;
Vi G[MAX_N];

void solve() {
  set<int> used;
  Vi path[2];
  used.insert(0);
  for (int d = 0; d < 2; d++) {
    path[d].push_back(0);
    while (true) {
      int v = path[d].back();
      bool brk = true;
      for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i];
        if (used.find(u) == used.end()) {
          brk = false;
          used.insert(u);
          path[d].push_back(u);
          break;
        }
      }
      if (brk) break;
    }
  }

  printf("%lu\n", used.size());
  for (int i = path[1].size() - 1; i > 0; i--) {
    printf("%d ", path[1][i] + 1);
  }
  for (int i = 0; i < path[0].size(); i++) {
    printf("%d ", path[0][i] + 1);
  }
  printf("\n");
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  solve();

  return 0;
}

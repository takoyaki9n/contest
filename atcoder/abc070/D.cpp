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

//#define DEBUG
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

const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

typedef struct{int to; ll cost;} edge;

int N, K, Q;
ll DEPTH[MAX_N];
vector<edge> G[MAX_N];

void calc_depth(int root) {
  for (int i = 0; i < N; i++) DEPTH[i] = INFL;
  DEPTH[root] = 0;
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].to;
      ll c = G[u][i].cost;
      if (DEPTH[u] + c < DEPTH[v]) {
        DEPTH[v] = DEPTH[u] + c;
        q.push(v);
      }
    }
  }
#ifdef DEBUG
for (int i = 0; i < N; i++) cout << i << " " << DEPTH[i] << endl;
#endif
}

ll solve(int x, int y) {
  return DEPTH[x] + DEPTH[y];
}

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge e, f;
    e.to = b; e.cost = c;
    f.to = a; f.cost = c;
    G[a].push_back(e);
    G[b].push_back(f);
  }

  cin >> Q >> K;
  K--;

  calc_depth(K);

  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << solve(x, y) << endl;
  }

  return 0;
}

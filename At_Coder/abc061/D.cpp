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

#define MAX_N   (1000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

struct edge{
  int to; ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

int N, M;
vector<edge> G[MAX_N], G_INV[MAX_N];
ll DIST[MAX_N];
set<int> REACH;

template <class T>
bool set_member(set<T> &st, T x) {
  return st.find(x) != st.end();
}

void calc_reachable(int s, vector<edge> g[], set<int> &st) {
  st.insert(s);
  stack<int> stk;
  stk.push(s);
  while (!stk.empty()) {
    int v = stk.top(); stk.pop();
    for (int i = 0; i < g[v].size(); i++) {
      int u = g[v][i].to;
      if (!set_member(st, u)) {
        stk.push(u);
        st.insert(u);
      }
    }
  }
}

string bellman_ford() {
  set<int> st_s, st_t;
  calc_reachable(0, G, st_s);
  calc_reachable(N - 1, G_INV, st_t);

  for (int i = 0; i < N; i++) DIST[i] = -INFL;
  DIST[0] = 0;

  for (int x = 0; x < N; x++) {
    bool update = false;
    for (int v = 0; v < N; v++) {
      for (int i = 0; i < G[v].size(); i++) {
        edge e = G[v][i];
        int u = e.to;
        if (DIST[u] < DIST[v] + e.cost) {
          if (x == N - 1 && set_member(st_s, u) && set_member(st_t, u))
            return "inf";
          DIST[u] = DIST[v] + e.cost;
          update = true;
        }
      }
    }
    if (!update) break;
  }
  return to_string(DIST[N - 1]);
}

void solve() {
  cout << bellman_ford() << endl;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back(edge(b, c));
    G_INV[b].push_back(edge(a, c));
  }

  solve();

  return 0;
}

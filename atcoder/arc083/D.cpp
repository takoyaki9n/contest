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

typedef struct{int to; int cost;} edge;


#define FST first
#define SND second

const int MAX_N = 300;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

ll N, A[MAX_N][MAX_N];

std::vector<edge> G[MAX_N];
ll D[MAX_N];

ll dijkstra(int s, int t) {
  for (int i = 0; i < N; i++) D[i] = (i == s) ? 0: INFL;
  D[s] = 0;
  std::priority_queue<Pi, vector<Pi>, greater<Pi> > pque;
  pque.push(Pi(0, s));
  while(!pque.empty()) {
    Pi p = pque.top(); pque.pop();
    int v = p.second;
    if (D[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (D[e.to] > D[v] + e.cost) {
        D[e.to] = D[v] + e.cost;
        pque.push(Pi(D[e.to], e.to));
      }
    }
  }
  return D[t];
}

void solve() {
  std::priority_queue<pair<int, Pi>, vector<pair<int, Pi> >, greater<pair<int, Pi> > > pq;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < i; j++) pq.push(make_pair(A[i][j], Pi(i, j)));
  }

  ll ans = 0;
  while(!pq.empty()) {
    auto p = pq.top(); pq.pop();
    ll c = p.FST, s = p.SND.FST, t = p.SND.SND;
    ll d = dijkstra(s, t);
    if (c < d) {
      edge e, f;
      e.to = t; e.cost = c;
      f.to = s; f.cost = c;
      G[s].push_back(e);
      G[t].push_back(f);
      ans += c;
    } else if (c > d) {
      ans = -1;
      break;
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++) cin >> A[i][j];
  }

  solve();

  return 0;
}

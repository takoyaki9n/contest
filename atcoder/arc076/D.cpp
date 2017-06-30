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
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

class union_find {
private:
  static const int max_n = MAX_N;
  int par[max_n];
public:
  void init(int n) {
    for (int x = 0; x < n; x++) par[x] = x;
  }
  int find(int x) {
    return (par[x] == x)? x: par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) par[y] = x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
};

int N;
Pi X[MAX_N], Y[MAX_N];

void solve() {
  sort(X, X + N);
  sort(Y, Y + N);

  priority_queue<pair<int, Pi>, vector<pair<int, Pi>>, greater<pair<int, Pi>>> pq;
  for (int i = 0; i < N - 1; i++) {
    pq.push(make_pair(abs(X[i].FST - X[i + 1].FST), Pi(X[i].SND, X[i + 1].SND)));
    pq.push(make_pair(abs(Y[i].FST - Y[i + 1].FST), Pi(Y[i].SND, Y[i + 1].SND)));
  }

  union_find uf;
  uf.init(N);
  ll ans = 0;
  int cnt = 0;
  while(cnt < N && !pq.empty()) {
    auto edge = pq.top(); pq.pop();
    int u = edge.SND.FST, v = edge.SND.SND;
    if (!uf.same(u, v)) {
#ifdef DEBUG
      cout << u << " " << v << " " << edge.FST << endl;
#endif
      uf.unite(u, v);
      ans += edge.FST;
      cnt++;
    }
  }

  cout << ans << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    X[i].SND = Y[i].SND = i;
    cin >> X[i].FST >> Y[i].FST;
  }

  solve();

  return 0;
}

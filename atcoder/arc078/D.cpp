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

const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 100000;                  // 10^5
// const int MAX_N = 1000000000;              // 10^9
// const ll  MAX_N = 1000000000000000000;     // 10^18
// const int BASE  = 1000000000 + 7;          // 10^9 + 7
// const int INFI  = 1000000000 + 7;          // 10^9 + 7
// const ll INFL  = 1000000000000000000 + 7; // 10^18 + 7

int N;
bool CLR[MAX_N];
vector<int> G[MAX_N];

Vi find_path(int s, int t) {
  int prev[MAX_N];
  memset(prev, -1, sizeof(prev));

  queue<int> q;
  q.push(s);
  prev[s] = s;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (prev[v] < 0) {
        prev[v] = u;
        q.push(v);
        if (v == t) break;
      }
    }
  }

  Vi path;
  int u = t;
  path.push_back(u);
  while (u != s) {
    u = prev[u];
    path.push_back(u);
  }

  return path;
}

void solve() {
  Vi path = find_path(0, N - 1);

  memset(CLR, false, sizeof(CLR));
  int len = path.size();
  for (int i = 0; i < len / 2; i++) {
    CLR[path[i]] = true;
  }

  stack<int> stk;
  stk.push(0);
  CLR[0] = true;
  int cnt = 1;
  while(!stk.empty()) {
    int u = stk.top(); stk.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (!CLR[v]) {
        CLR[v] = true;
        cnt++;
        stk.push(v);
      }
    }
  }

  if (cnt <= N / 2) {
    cout << "Snuke" << endl;
  } else {
    cout << "Fennec" << endl;
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  solve();

  return 0;
}

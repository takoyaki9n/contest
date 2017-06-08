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
#include <unordered_set>

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

#define MAX_N   (100000)                  // 10^5
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
set<int> G[MAX_N];
bitset<MAX_N> V(0);

void make_tree(int v) {
  for (auto u: G[v]) {
    G[u].erase(v);
    make_tree(u);
  }
}

void remove_match(int v) {
  for (auto u : G[v]) {
    remove_match(u);
    if (V[v] && V[u]) V[v] = V[u] = 0;
  }
}

string winner() {
  int root = 0;
  make_tree(root);
  remove_match(root);
  return V.none()? "Second": "First";
}

int main() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].insert(b); G[b].insert(a);
    V.set(a); V.set(b);
  }

  string ans = winner();
  cout << ans << endl;

  return 0;
}
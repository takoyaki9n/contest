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

int N;
ll A[MAX_N + 1], B[MAX_N + 1];

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

bool check() {
  map<ll, int> mp;
  for (int i = 0; i <= N; i++) mp[A[i]]++;

  for (int i = 0; i <= N; i++) {
    if (mp[B[i]] == 0) return false;
    mp[B[i]]--;
  }

  return true;
}

int calc() {
  A[N] = B[N] = 0;
  for (int i = 0; i < N; i++) {
    A[N] ^= A[i]; B[N] ^= B[i];
  }

  if(!check()) return -1;

  map<ll, int> mp;
  int id = 0;
  for (int i = 0; i <= N; i++) {
    if (A[i] != B[i]) {
      if (mp.count(A[i]) == 0) mp[A[i]] = id++;
      if (mp.count(B[i]) == 0) mp[B[i]] = id++;
    }
  }

#ifdef DEBUG
  for (auto kv : mp) {
    cout << kv.first << " : " << kv.second << endl;
  }
#endif

  union_find uft;
  uft.init(id);
  for (int i = 0; i <= N; i++) {
    if (A[i] != B[i]) uft.unite(mp[A[i]], mp[B[i]]);
  }

  int e = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) e++;
  }

  int c = 0;
  for (int i = 0; i < id; i++) {
    if (uft.find(i) == i) c++;
  }

#ifdef DEBUG
  cout << e << ", " << c << endl;
#endif

  return (mp.count(A[N]) == 0)? e + c: e + c - 1;
}

void solve() {
  cout << calc() << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  solve();

  return 0;
}

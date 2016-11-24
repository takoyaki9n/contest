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
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;

#define INF   (1e9 + 7)
#define MAX_L (1000000000)
#define MAX_N (50000)

int L, N, M;
int D[MAX_N];

bool remove_rock(int w) {
  int dl = 0, n = 0;
  for (size_t i = 0; i < N; i++) {
    if (D[i] - dl < w) {
      n++;
    } else {
      dl = D[i];
    }
  }
  if (L - dl < w) n++;
  return n <= M;
}

void solve() {
  sort(D, D + N);
  int wl = 0, wr = L;

  while (wr - wl > 1) {
    int wm = (wl + wr) / 2;
//    printf("%d %d %d\n", wl, wm, wr);
    if (remove_rock(wm)) {
      wl = wm;
    } else {
      wr = wm;
    }
  }

  printf("%d\n", wl);
}

int main() {
  scanf("%d %d %d", &L, &N, &M);
  for (size_t i = 0; i < N; i++) {
    scanf("%d", &D[i]);
  }

  solve();

  return 0;
}

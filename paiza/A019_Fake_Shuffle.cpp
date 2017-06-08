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
#define MAX_N (8)
#define MAX_S (24)
#define MASK  (7) 

int N, S;
int START, TARG, SHUFFLE[MAX_S][MAX_N];
std::map<int, int> TBL;

void p_pile(int pile) {
  for (int i = 0; i < N; i++) {
    int shift = 3 * (N - i - 1);
    int d = (pile & (MASK << shift)) >> shift;
    printf("%d ", d);
  }
  printf("\n");
}

int do_shuffle(int pile, int *shfl) {
  int result = 0;
  for (int i = 0; i < N; i++) {
    int j = shfl[i];
    int shift_i = 3 * (N - i - 1);
    int shift_j = 3 * (N - j - 1);
    int d = (pile & (MASK << shift_j)) >> shift_j;
    result = result | (d << shift_i);
  }
  return result;
}

int search() {
  queue<int> q;
  q.push(START);
  TBL[START] = 0;
  while (!q.empty()) {
    int pile = q.front(); q.pop();
    if (pile == TARG) return TBL[pile];
    // printf("pile = ");
    // p_pile(pile);
    for (int i = 0; i < S; i++) {
      int next = do_shuffle(pile, SHUFFLE[i]);
      if (TBL.count(next) == 0) {
        TBL[next] = TBL[pile] + 1;
        q.push(next);
      }
    }
  }
  return -1;
}

void solve() {
  int ans = search();

  printf("%d\n", ans);
}

int main() {
  scanf("%d", &N);
  START = 0;
  for (int i = 0; i < N; i++) {
    START = (START << 3) | i;
  }
  TARG = 0;
  for (int i = 0; i < N; i++) {
    int d;
    scanf("%d", &d);
    TARG = (TARG << 3) | d;
  }
  scanf("%d", &S);
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < N; j++) {
      int d;
      scanf("%d", &d);
      SHUFFLE[i][j] = d;
    }
  }
  solve();

  return 0;
}

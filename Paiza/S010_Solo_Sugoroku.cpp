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
#define MAX_N (1000)

const int T = 0, B = 1;//, U = 2, D = 3, L = 4, R = 5;
int N, DICE[6], DICE_INV[7], P[MAX_N];

void solve() {
  int ans = 0;
  int dt = DICE[T], db = DICE[B];
  for (int i = 1; i < N; i++) {
    if (db == P[i]) {
      ans += 2;
      swap(dt, db);
    } else if (dt != P[i]) {
      ans += 1;
      dt = P[i];
      int t = DICE_INV[dt];
      int b = 2 * (t / 2) + 1 - (t % 2);
      db = DICE[b];
    }
  }

  printf("%d\n", ans);
}

int main() {
  for (int i = 0; i < 6; i++) {
    scanf("%d", &DICE[i]);
    DICE_INV[DICE[i]] = i;
  }
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &P[i]);

  solve();

  return 0;
}

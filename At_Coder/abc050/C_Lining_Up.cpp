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

#define INF   (1000000000 + 7)
#define MAX_N (100000)
#define MAX_N (100000)

int N;
int A[MAX_N];
int COUNTS[MAX_N];

ll solve() {
  for (int i = 0; i < N; i++) {
    int a = A[i];
    if (a < 0 || N <= a) return 0;
    if (a % 2 == N % 2) return 0;
    COUNTS[a / 2]++;
  }

  if (N % 2 == 1) {
    if (COUNTS[0] != 1) return 0;
  } else {
    if (COUNTS[0] != 2) return 0;    
  }

  for (int i = 1; i < (N + 1) / 2; i++) {
    if (COUNTS[1] != 2) return 0;
  }

  ll ans = 1;
  for (int i = 0; i < N / 2; i++) {
    ans = (ans * 2) % INF;
  }
  return ans;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }

  printf("%lld\n", solve());

  return 0;
}

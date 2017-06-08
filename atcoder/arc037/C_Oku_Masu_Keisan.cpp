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
#define MAX_N (30000)
#define MAX_K (MAX_N * MAX_N)
#define MAX_A (1000000000)

ll N, K;
ll A[MAX_N], B[MAX_N];

ll count_le(ll v) {
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += (int) (lower_bound(B, B + N, v / A[i] + 1) - B);
  }
//  printf("cnt = %lld\n", cnt);
  return cnt;
}

void solve() {
//  sort(A, A + N);
  sort(B, B + N);

/*  for (int i = 0; i < N; i++) printf("%lld ", A[i]);
  printf("\n");
  for (int i = 0; i < N; i++) printf("%lld ", B[i]);
  printf("\n");*/
  
  ll vl = 0, vr = B[N-1] * INF;
  while (vr - vl > 1) {
    ll vm = (vl + vr) / 2;
//    printf("%lld %lld %lld\n", vl, vm, vr);
    if (count_le(vm) < K) {
      vl = vm;
    } else {
      vr = vm;
    }
  }

  printf("%lld\n", vr);
}

int main() {  
  scanf("%lld %lld", &N, &K);
  for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
  for (int i = 0; i < N; i++) scanf("%lld", &B[i]);

  solve();

  return 0;
}

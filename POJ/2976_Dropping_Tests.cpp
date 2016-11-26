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
#define MAX_A (1000000000)
#define EPS   (1e-5)

int N, K;
int A[MAX_N], B[MAX_N];
double C[MAX_N];

bool calc_average(double x) {
  for (int i = 0; i < N; i++) C[i] = A[i] - x * B[i];
  
  sort(C, C + N);

  double sum = 0;
  for (int i = K; i < N; i++) sum += C[i];
  
  return sum >= 0;
}

void solve() {
  double xl = 0.0, xr = 1.1;
  while (xr - xl > EPS) {
    double xm = (xl + xr) * 0.5;
//    printf("%f %f %f\n", xl, xm, xr);
    if (calc_average(xm)) {
      xl = xm;
    } else {
      xr =xm;
    }
  }

  printf("%d\n", (int) (xr * 100 + 0.5));
}

int main() {
  while (true) {
    scanf("%d %d", &N, &K);
    if (N == 0) break;
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);  
    
    solve();
  }


  return 0;
}

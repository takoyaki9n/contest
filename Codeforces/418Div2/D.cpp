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

//#define DEBUG
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

#define MAX_N   (1000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

struct circle {
  double x, y, r;
  circle() : x(0.0), y(0.0), r(0.0) {}
  circle(double x, double y, double r) : x(x), y(y), r(r) {}
};

bool cmp(const circle &c1, const circle &c2) {
  return c1.r > c2.r;
}

int N;
circle C[MAX_N];
int PAR[MAX_N], RNK[MAX_N];
double PI = atan(1) * 4;

bool included(const circle &c1, const circle &c2) {
  double dx = c1.x - c2.x, dy = c1.y - c2.y;
  double dr2 = dx * dx + dy * dy;
  return c1.r < c2.r && dr2 < c2.r * c2.r;
}

void solve() {
  sort(C, C + N, cmp);

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    printf("%f %f %f\n", C[i].x, C[i].y, C[i].r);
  }
#endif

  for (int i = 0; i < N; i++) {
    PAR[i] = i; RNK[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (included(C[i], C[j])) {
        PAR[i] = j;
        RNK[i] = RNK[j] + 1;
        break;
      }
    }
  }

#ifdef DEBUG
  for (int i = 0; i < N; i++) {
    printf("%d %d\n", PAR[i], RNK[i]);
  }
#endif

  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    double area = PI * C[i].r * C[i].r;
    if (RNK[i] > 1 && RNK[i] % 2 == 0) area *= -1.0;
    ans += area;
  }

  printf("%.10f\n", ans);

}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    double x, y, r;
    cin >> x >> y >> r;
    C[i] = circle(x, y, r);
  }

  solve();

  return 0;
}

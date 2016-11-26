#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

typedef long long ll;
#define MAX_N (1000)

int N, D;
double I[MAX_N][2];

int main() {
  while (true) {
    scanf("%d %d", &N, &D);
    if (N == 0 && D == 0) { break; }
    bool flag = true;
    for (size_t i = 0; i < N; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      if (y > D) { flag = false; break; }
      I[i][0] = x - sqrt((double) D*D - y*y);
      I[i][1] = x + sqrt((double) D*D - y*y);
      printf("[%lf, %lf]\n", I[i][0], I[i][1]);
    }

    int count = 0;
    if (flag) {
    } else {
      count = -1;
    }

    printf("%d\n", count);
  }
  return 0;
}

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (25000)
#define MAX_T (1000000)

struct Period {
  int start;
  int end;
};

int N, T;
Period Cows[MAX_N];

bool operator<(const Period& left, const Period& right) {
        return left.end < right.end;
}

int main() {
  scanf("%d %d", &N, &T);
  for (size_t i = 0; i < N; i++) {
    scanf("%d %d", &(Cows[i].start), &(Cows[i].end));
  }

  sort(Cows, Cows + N);

  int count = 0;
  int t = 1;
  int n = 0;
  while (t <= T) {
    int max_e = -1;
    for (size_t i = n; i < N; i++) {
      int s = Cows[i].start, e = Cows[i].end;
      if (s <= t && t <= e && max_e < e) {
        max_e = e;
        n = i;
      }
    }
    if (max_e < 0) {
      count = -1;
      break;
    } else {
      count++;
      t = max_e + 1;
      n++;
    }
  }

  printf("%d\n", count);
  return 0;
}

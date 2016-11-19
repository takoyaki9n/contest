#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef std::pair<int, int> pii;
typedef long long ll;

#define MAX_C (2500)
#define MAX_L (2500)

int C, L;
pii COW[MAX_C];
pii LOT[MAX_L];

struct Cmp {
	bool operator()(const pii &a, const pii &b) const {
		return a.second > b.second;
	}
};

void solve() {
  sort(COW, COW + C);
  sort(LOT, LOT + L);

  int ans = 0;
  std::priority_queue<pii, std::vector<pii>, Cmp> pq;
  size_t i = 0;
  for (size_t j = 0; j < L; j++) {
    if (i >= C && pq.empty()) break;
    int spf = LOT[j].first;
    while (!pq.empty() && pq.top().second < spf) {
      // pii cow = pq.top();
      // printf("%lu: pop [%d, %d]\n", j, cow.first, cow.second);
      pq.pop();
    }
    while (i < C && COW[i].first <= spf) {
      if (spf <= COW[i].second) {
        pq.push(COW[i]);
        // pii cow = COW[i];
        // printf("%lu: push [%d, %d]\n", j, cow.first, cow.second);
      }
      i++;
    }
    int cnt = LOT[j].second;
    while (cnt > 0 && !pq.empty()) {
      cnt--;
      ans++;
      // pii cow = pq.top();
      // printf("%lu: cnt [%d, %d] ans = %d\n", j, cow.first, cow.second, ans);
      pq.pop();
    }
  }

  printf("%d\n", ans);
}

int main() {
  std::cin >> C >> L;
  for (size_t i = 0; i < C; i++) {
    scanf("%d %d", &COW[i].first, &COW[i].second);
  }
  for (size_t i = 0; i < L; i++) {
    scanf("%d %d", &LOT[i].first, &LOT[i].second);
  }

  solve();

  return 0;
}

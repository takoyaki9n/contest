#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

#define MAX_N (10000)
#define MAX_L (1000000)
#define MAX_P (1000000)
#define MAX_B (100)

int N, L, P;
pair<int, int> F[MAX_N + 1];

int solve(){
  F[N].first = L; F[N].second = 0;
  int p = P;
  int x = 0;
  int ans = 0;

  std::priority_queue<int> pq;
  for (size_t i = 0; i <= N; i++) {
    int d = F[i].first - x;
    while (p - d < 0) {
      if (pq.empty()) {
        return -1;
      } else {
        p += pq.top(); pq.pop();
        ans++;
      }
    }
    p -= d;
    pq.push(F[i].second);
    x = F[i].first;
  }
  return ans;
}

int main() {
  std::cin >> N;
  for (size_t i = 0; i < N; i++) {
    std::cin >> F[i].first >> F[i].second;
  }
  std::cin >> L >> P;
  for (size_t i = 0; i < N; i++) {
    F[i].first = L - F[i].first;
  }
  sort(F, F + N);


  std::cout << solve() << std::endl;
  return 0;
}

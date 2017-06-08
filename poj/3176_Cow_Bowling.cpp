#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_N (26)
#define MAX_M (2000)

int N, M;
char ID[MAX_M];
int dp[MAX_M][MAX_M], costs[MAX_M][2];

int main() {
  scanf("%d %d", &N, &M);
  scanf("%s", ID);
  for (size_t i = 0; i < N; i++) {
    int c = getchar();
    scanf("%d %d", &costs[c][0], &costs[c][1]);
  }

  printf("%d %d %s\n", N, M, ID);
  for (size_t i = 0; i < MAX_N; i++) {
    printf("%c %d %d\n", (char) 'a' + i, costs[i][0], costs[i][1]);
  }



  return 0;
}

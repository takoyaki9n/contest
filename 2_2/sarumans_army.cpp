#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_N 1000
#define MAX_R 1000

int N, R;
int X[MAX_N];

void print_array(int *ar, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

int main() {
  while (true) {
    scanf("%d %d\n", &R, &N);
    if (R < 0) break;
    for (size_t i = 0; i < N; i++) {
      scanf("%d", &X[i]);
    }
    sort(X, X + N);

    int count = 0;
    int i = 0;
    while (i < N) {
      int j = i + 1;
      while (j < N && X[j] - X[i] <= R) j++;
      int k = j; j--;
      while (k < N && X[k] - X[j] <= R) k++;
//      printf("i = %d, j = %d, k = %d\n", i, j, k);
      i = k;
      count++;
    }
    printf("%d\n", count);
  }
  return 0;
}

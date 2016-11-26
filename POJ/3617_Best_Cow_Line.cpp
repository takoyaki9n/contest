#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_N 2000

char S[MAX_N + 1];

int main() {
  int N;
  scanf("%d\n", &N);
  for (size_t i = 0; i < N; i++) {
    scanf("%c\n", &S[i]);
  }
  S[N] = '\0';

  int l, r, c;
  c = 0;
  l = 0; r = N - 1;
  while (l <= r) {
    bool left = true;
    for (size_t i = 0; i <= r - l; i++) {
      if (S[l + i] < S[r - i]) {
        left = true;
        break;
      } else if (S[l + i] > S[r - i]) {
        left = false;
        break;
      }
    }
    if (left) {
      putchar(S[l]); l++;
    } else {
      putchar(S[r]); r--;
    }
    c++;
    if (c % 80 == 0) {
      putchar('\n');
    }
  }
  if (c % 80 != 0) {
    putchar('\n');
  }
  return 0;
}

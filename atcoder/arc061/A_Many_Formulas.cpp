#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAX_L (10)

char S[MAX_L + 1];

void print_array(int *ar, int n) {
  for (size_t i = 0; i < n; i++) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

ll my_atoi(char *s, int l, int r) {
  ll val = 0;
  for (size_t i = l; i < r; i++) {
    val = 10 * val + (s[i] - '0');
  }
  return val;
}

ll comb(int n, int k) {
  ll c = 1;
  for (size_t i = k + 1; i <= n; i++) {
    c *= i;
  }
  for (size_t i = 2; i <= n - k; i++) {
    c /= i;
  }
  return c;
}

ll search(char *s, int n, int l, int r) {
//  printf("%lld, %d\n", my_atoi(s, l, r), n);
  if (n <= 0) { return my_atoi(s, l, r); }
  ll cost = 0;
  for (size_t i = l + 1; n - 1 < r - i; i++) {
    cost += search(s, 0, l, i) * comb(r - i - 1, n - 1);
    cost += search(s, n - 1, i, r);
  }
  return cost;
}

int main() {
  scanf("%s", S);

  ll cost = 0;
  int L = std::strlen(S);
  for (size_t i = 0; i < L; i++) {
    cost += search(S, i, 0, L);
  }

  printf("%lld\n", cost);
  return 0;
}

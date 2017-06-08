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
#define MAX_P (1000000000)

ll P, A;

ll mod_pow(ll p, ll a, ll mod) {
  ll res = 1;
  while (p > 0) {
    if (p & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    p >>= 1;
  }
  return res;
}

bool is_prime(ll p) {
  if (p == 1) return false;
  for (size_t i = 2; i * i <= p; i++) {
    if (p % i == 0) return false;
  }
   return true;
}

void solve() {
  if (!is_prime(P) && mod_pow(P, A, P) == A) {
    printf("yes\n");
  } else {
    printf("no\n");
  }
}

int main() {
  while (true) {
    scanf("%lld %lld", &P, &A);
    if (P == 0) break;

    solve();
  }

  return 0;
}

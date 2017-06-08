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
#define MAX_N (10000000)

int N;

void solve() {
  int ans = 0;

  printf("%d\n", ans);
}

int main() {
  int i = 0;
  printf("{");
  while (scanf("%d", &N) != EOF) {
    printf("%d,", N);
    i++;
  }
  printf("};\n");
  printf("%d", i);
  return 0;
}

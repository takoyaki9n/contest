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
#define MAX_N (100000)
#define MAX_X (1000000000)

int N;
int X[MAX_N];

void solve() {
  vector<int> dx;
  for (int i = 0; i < N; i++) 
    for (int j = i + 1; j < N; j++) 
      dx.push_back(abs(X[i] - X[j]));
  sort(dx.begin(), dx.end());
  int m = (N - 1) * N / 4;

  for (int i = 0; i < dx.size(); i++) {
    printf("%d:%d ", i + 1, dx[i]);
  }
  printf("\n");

  printf("%d\n", dx[m]);
}

int main() {
  while (scanf("%d", &N) != EOF) {
    for (int i = 0; i < N; i++) scanf("%d", &X[i]);
    
    solve();
  }

  return 0;
}

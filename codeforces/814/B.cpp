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

#define DEBUG
#ifdef DEBUG
#define debug_printf printf
#else
#define debug_printf 1 ? 0 : printf
#endif

using namespace std;
typedef long long int ll;
typedef vector<ll> Vl;
typedef vector<int> Vi;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pl;

#define FST first
#define SND second

#define MAX_N   (1000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N;
int A[MAX_N], B[MAX_N], P[MAX_N], C[MAX_N + 1];

void solve() {
  for (int i = 0; i < N + 1; i++) C[i] = 0;

  int idx[2] = {-1, -1};
  for (int i = 0; i < N; i++) {
    if (A[i] == B[i]) {
      int a = A[i];
      P[i] = a;
      C[a]++;
    } else {
      for (int j = 0; j < 2; j++){
        if (idx[j] < 0) {
          idx[j] = i;
          break;
        }
      }
    }
  }

  int xs[2] = {-1, -1};
  for (int i = 1; i < N + 1; i++) {
    if (C[i] == 0) {
      for (int j = 0; j < 2; j++) {
        if (xs[j] < 0) {
          xs[j] = i;
          break;
        }
      }
    }
  }

  if (idx[1] < 0) {
    P[idx[0]] = xs[0];
  } else {
    int a = A[idx[0]], b = A[idx[1]], c = B[idx[0]], d = B[idx[1]];
    if (C[a] == 0 && C[b] == 0 && C[c] == 0 && C[d] == 0) {
      P[idx[0]] = xs[0];
      P[idx[1]] = xs[1];
    } else {
      if (C[a] > 0 || C[d] > 0) {
        P[idx[0]] = c;
        P[idx[1]] = b;
      } else {
        P[idx[0]] = a;
        P[idx[1]] = d;
      }
    }
  }


  for (int i = 0; i < N; i++) cout << P[i] << " ";
  cout << endl;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  solve();

  return 0;
}

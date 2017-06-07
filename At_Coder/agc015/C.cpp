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

//#define DEBUG
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

#define FST first
#define SND second

#define MAX_N   (2000)                  // 10^3
#define MAX_Q   (200000)                  // 10^5
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int N, M, Q;
string MAP[MAX_N + 2];
int CNTB[MAX_N + 1][MAX_N + 1];
int CNTV[MAX_N + 1][MAX_N + 1];
int CNTH[MAX_N + 1][MAX_N + 1];

void print_matrix(int cnt[MAX_N + 1][MAX_N + 1], int n, int m) {
  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1; j++) {
      cout << cnt[i][j];
    }
    cout << endl;
  }
}

int count_of(int i, int j, int cnt[MAX_N + 1][MAX_N + 1]) {
  return cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
}

void make_matrices() {
  for (int i = 0; i < N + 1; i++) CNTB[i][0] = CNTV[i][0] = CNTH[i][0] = 0;
  for (int i = 0; i < M + 1; i++) CNTB[0][i] = CNTV[0][i] = CNTH[0][i] = 0;

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < M + 1; j++) {
      CNTB[i][j] = count_of(i, j, CNTB);
      CNTV[i][j] = count_of(i, j, CNTV);
      CNTH[i][j] = count_of(i, j, CNTH);
      if (MAP[i][j] == '1') {
        CNTB[i][j]++;
        if (MAP[i - 1][j] == '1') CNTV[i][j]++;
        if (MAP[i][j - 1] == '1') CNTH[i][j]++;
      }
    }
  }

  #ifdef DEBUG
  print_matrix(CNTB, N, M);
  cout << endl;
  print_matrix(CNTV, N, M);
  cout << endl;
  print_matrix(CNTH, N, M);
  cout << endl;
  #endif

}

int count_of_range(int r1, int c1, int r2, int c2, int cnt[MAX_N + 1][MAX_N + 1]) {
  return cnt[r2][c2] - cnt[r2][c1 - 1] - cnt[r1 - 1][c2] + cnt[r1 - 1][c1 - 1];
}

int query(int r1, int c1, int r2, int c2) {
  int b = count_of_range(r1, c1, r2, c2, CNTB);
  int v = count_of_range(r1 + 1, c1, r2, c2, CNTV);
  int h = count_of_range(r1, c1 + 1, r2, c2, CNTH);
  return b - v - h;
}

int main() {
  cin >> N >> M >> Q;
  MAP[0] = string(M + 2, '0');
  MAP[N + 1] = string(M + 2, '0');
  for (int i = 1; i <= N; i++) {
    cin >> MAP[i];
    MAP[i] = "0" + MAP[i] + "0";
  }

#ifdef DEBUG
  for (int i = 0; i < N + 2; i++) cout << MAP[i] << endl;
  cout << endl;
#endif

  make_matrices();

  for (int i = 0; i < Q; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << query(r1, c1, r2, c2) << endl;
  }


  return 0;
}

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

#define INF   (1e9 + 7)
#define MAX_N (100)

int T, N, M;
bool H[MAX_N], V[MAX_N], D[2 * MAX_N + 1], U[2 * MAX_N + 1];
char BD[MAX_N][MAX_N + 1];
map<Pi, char> LOG;

void print_bd() {
#ifdef DEBUG
  for (int i = 0; i < N; i++) printf("%s\n", BD[i]);
#endif
}

void check(char m, int r, int c) {
  BD[r][c] = (BD[r][c] == '.')? m: 'o';
//  debug_printf("put: %c %d %d\n", BD[r][c], r + 1, c + 1);
  LOG[Pi(r, c)] = BD[r][c];
}

void place_x() {
  for (int r = 0; r < N; r++) {
    if (V[r]) continue;
    for (int c = 0; c < N; c++)
      if (!H[c]) {
        V[r] = H[c] = true;
        check('x', r, c);
        break;
      }
  }
}

void place_p() {
  if(!D[0] && !U[N - 1]) {
    check('+', 0, 0);
    D[0] = U[N - 1] = true;
  }
  if(!D[N - 1] && !U[0]) {
    check('+', 0, N - 1);
    D[N - 1] = U[0] = true;
  }
  for (int x = 0; x < 2 * N - 1; x++) {
    if (D[x]) continue;
    int yl = abs(N - 1 - x), yr = 2 * (N - 1) - yl;
//    debug_printf("x = %d, %d <= y <= %d\n", x, yl, yr);

    for (int y = yl; y <= yr; y += 2) {
      if (!U[y]) {
        D[x] = U[y] = true;
        int r = (x + y - N + 1) / 2, c = (x - y + N - 1) / 2;
        check('+', r, c);
        break;
      }
    }
  }
}

int calc_score(){
  int score = 0;
  for (int i = 0; i < N; i++)
    if (H[i]) score++;
  for (int i = 0; i < 2 * N - 1; i++)
    if (D[i]) score++;
  return score;
}

void print_ans(int t) {
  print_bd();
  int score = calc_score();
  int updates = LOG.size();
  printf("Case #%d: %d %d\n", t + 1, score, updates);
  for (map<Pi,char>::iterator it = LOG.begin(); it != LOG.end(); ++it) {
    printf("%c %d %d\n", it->second, it->first.first + 1, it->first.second + 1);
  }
}

int main() {
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> M;
    debug_printf("#%d: %d %d\n", t + 1, N, M);

    LOG.clear();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) BD[i][j] = '.';
      BD[i][N] = '\0';
    }
    for (int i = 0; i < N; i++)         H[i] = V[i] = false;
    for (int i = 0; i < 2 * N - 1; i++) D[i] = U[i] = false;

    for (int i = 0; i < M; i++) {
      char m; int r, c;
      cin >> m >> r >> c;
      r--; c--;
      BD[r][c] = m;
      if (m == 'x' || m == 'o') V[r] = H[c] = true;
      if (m == '+' || m == 'o') D[r + c] = U[r - c + N - 1] = true;
      debug_printf("#%d:  %c %d %d\n", t + 1, m, r + 1, c + 1);
    }

    place_x();
    place_p();

    print_ans(t);
  }

  return 0;
}

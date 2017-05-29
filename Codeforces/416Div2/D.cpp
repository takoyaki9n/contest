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

#define MAX_N   (100)                  // 10^4
// #define MAX_N   (1000000000)              // 10^9
// #define MAX_N   (1000000000000000000)     // 10^18
#define BASE    (1000000000 + 7)          // 10^9 + 7
#define INFI    (1000000000 + 7)          // 10^9 + 7
#define INFL    (1000000000000000000 + 7) // 10^18 + 7

int DR[4] = {-1, 0, 0, 1};
int DC[4] = {0, -1, 1, 0};
char CMDS[4] = {'U', 'L', 'R', 'D'};

int N, M;
string MAP[MAX_N + 2];
int FLOW[MAX_N + 2][MAX_N + 2];
int GR, GC;
int UD = 0, LR = 0;

int rev_dir(int d) {
  return 3 - d;
}

int cmd_inv(char cmd) {
  for (int d = 0; d < 4; d++)
    if (cmd == CMDS[d]) return d;
  return 4;
}

char get_cmd(int r, int c) {
  int d = FLOW[r][c];
  if (d == 0 || d == 3) {
    if (UD == -1) d = rev_dir(d);
  } else if (d == 1 || d == 2) {
    if (LR == -1) d = rev_dir(d);
  }
  return CMDS[d];
}

void guess_move(int &r, int &c, char cmd) {
  int d = cmd_inv(cmd);
  if (d == 0 || d == 3) {
    if (UD == -1) d = rev_dir(d);
  } else if (d == 1 || d == 2) {
    if (LR == -1) d = rev_dir(d);
  }
  int nr = r + DR[d], nc = c + DC[d];
  if (MAP[nr][nc] != '#') { r = nr; c = nc; }
}

void init_flow() {
  for (int i = 0; i < N + 2; i++)
    for (int j = 0; j < M + 2; j++) FLOW[i][j] = 4;

  queue<Pi> q;
  q.push(Pi(GR, GC));
  FLOW[GR][GC] = 5;
  while(!q.empty()) {
    Pi p = q.front(); q.pop();
    int r = p.FST, c = p.SND;
    for (int d = 0; d < 4; d++) {
      int nr = r + DR[d], nc = c + DC[d];
      if (MAP[nr][nc] == '.' && FLOW[nr][nc] >= 4) {
        Pi np = Pi(nr, nc);
        q.push(np);
        FLOW[nr][nc] = rev_dir(d);
      }
    }
  }
}

void play() {
  int r = 1, c = 1;
  while(true) {
    if (r == GR && c == GC) break;

    char cmd = get_cmd(r, c);
    int nr = r, nc = c;
    guess_move(nr, nc, cmd);

    cout << cmd << endl;
    fflush(stdout);
    cin >> r >> c;

    if (r != nr|| c != nc) {
      if (cmd == 'U' || cmd == 'D') UD = -1;
      if (cmd == 'L' || cmd == 'R') LR = -1;
    }
  }
}

int main() {
  cin >> N >> M;
  MAP[0] = string(M + 2, '#');
  MAP[N + 1] = string(M + 2, '#');
  for (int i = 1; i < N + 1; i++) {
    cin >> MAP[i];
    MAP[i] = "#" + MAP[i] + "#";

    int gc = MAP[i].find_first_of('F');
    if (gc != string::npos) { GR = i; GC = gc; }
  }

#ifdef DEBUG
  cout << "goal: " << GR << " " << GC << endl;
  for (int i = 0; i < N + 2; i++) {
    cout << MAP[i] << endl;
  }
  cout << endl;
#endif

  init_flow();
#ifdef DEBUG
  for (int i = 0; i < N + 2; i++) {
    for (int j = 0; j < M + 2; j++) cout << FLOW[i][j];
    cout << endl;
  }
  cout << endl;
#endif

  play();

  return 0;
}

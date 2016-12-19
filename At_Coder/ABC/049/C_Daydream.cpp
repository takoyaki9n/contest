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
#define MAX_L (100000)

string WORDS[4] = {"dream", "dreamer", "erase", "eraser"};
string S;

bool match(int n) {
  if (n == S.size()) return true;

  for (int i = 0; i < 4; i++) {
    string w = WORDS[i];
    bool flag = true;
    for (int j = 0; j < w.size(); j++) {
      if (n + j > S.size() || w[j] != S[n + j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (match(n + w.size())) return true;
    }
  }

  return false;
}

void solve() {
  if (match(0)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main() {
  for (int i = 0; i < 4; i++) {
    std::reverse(WORDS[i].begin(), WORDS[i].end());
  }
  cin >> S;
  std::reverse(S.begin(), S.end());
  
  solve();
  
  return 0;
}

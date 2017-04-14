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

#define INF   (1e9 + 7)
#define MAX_N (1000)

int T;
string S;

string solve() {
  string ans = S.substr(0, 1);
  for (int i = 1; i < S.size(); i++) {
    if (S[i] < ans[0]) {
      ans.push_back(S[i]);
    } else {
      ans.insert(ans.begin(), S[i]);
    }
  }
  return ans;
}

int main() {
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> S;
    string ans = solve();
    printf("Case #%d: %s\n", t, ans.c_str());
  }

  return 0;
}

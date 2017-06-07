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
int N = 5;
char vowels[5] = {'a', 'i', 'u', 'e', 'o'};


int main() {
  char c;
  scanf("%c", &c);

  for (int i = 0; i < N; i++) {
    if (c == vowels[i]) {
      printf("vowel\n");
      return 0;
    }
  }
  
  printf("consonant\n");
  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_M 100

int dxy[8][2] = {
  {-1, -1}, {-1, 0}, {-1, 1},
  {0,  -1},          {0,  1},
  {1,  -1}, {1,  0}, {1,  1}
};

int N, M;

bool is_inside(int i, int j, int N, int M) {
  return (0 <= i) && (i < N) && (0 <= j) && (j < M);
}

int main() {
  int N, M;
  cin >> N >> M; cin.ignore();
  std::vector<string> map;
  for (size_t i = 0; i < N; i++) {
    std::string row;
    std::cin >> row;
    map.push_back(row);
  }
  for (size_t i = 0; i < N; i++) {
//    std::cout << map[i] << std::endl;
  }

  bool flags[N][M];
  for (size_t i = 0; i < N; i++)
    for (size_t j = 0; j < M; j++) flags[i][j] = false;

  int count = 0;
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < M; j++) {
      if (!flags[i][j] && map[i][j] == 'W') {
        count++;
        stack<int> stk_x;
        stack<int> stk_y;
        stk_x.push(i);
        stk_y.push(j);
        flags[i][j] = true;
        while (!stk_x.empty()) {
          int x = stk_x.top(); stk_x.pop();
          int y = stk_y.top(); stk_y.pop();
//          std::cout << x << " " << y << std::endl;
          for (size_t k = 0; k < 8; k++) {
            int u = x + dxy[k][0]; int v = y + dxy[k][1];
//            std::cout << "    " << u << " " << v << std::endl;
            if (is_inside(u, v, N, M) && !flags[u][v] && map[u][v] == 'W') {
              stk_x.push(u);
              stk_y.push(v);
              flags[u][v] = true;
            }
          }
        }
//        std::cout << "count = " << count << std::endl;
      }
    }
  }

  std::cout << count << std::endl;
}

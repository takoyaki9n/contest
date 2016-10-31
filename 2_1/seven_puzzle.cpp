#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int k = 3;
int N = 1 << k;

// void p_id(int id) {
//   std::string s = "";
//   for (size_t i = 0; i < N; i++) {
//     s = std::to_string(id & (N - 1)) + s;
//     id >>= k;
//   }
//   std::cout << s << std::endl;
// }

int swap(int i, int j, int id){
  int sft_i = i * k;
  int sft_j = j * k;
  int x = id & ((N - 1) << sft_i);
  int y = id & ((N - 1) << sft_j);
  id = id ^ x;
  id = id ^ y;
  id = id | ((x >> sft_i) << sft_j);
  id = id | ((y >> sft_j) << sft_i);
  return id;
}

int get_id(int b[]) {
  int id = 0;
  for (size_t i = 0; i < N; i++) id = (id << k) | b[i];
  return id;
}

int get_pos0(int id) {
  for (size_t i = 0; i < N; i++) {
    int d = id & (N - 1);
    if (d == 0) return i;
    id >>= k;
  }
  return -1;
}

void next_ids(int id, std::vector<int> *v){
  int pos0 = get_pos0(id);
  int No2 = N >> 1;
  v->clear();
  if (pos0 < No2) {
    v->push_back(swap(pos0, pos0 + No2, id));
    if (pos0 != 0)       v->push_back(swap(pos0, pos0 - 1, id));
    if (pos0 != No2 - 1) v->push_back(swap(pos0, pos0 + 1, id));
  } else {
    v->push_back(swap(pos0, pos0 - No2, id));
    if (pos0 != No2)     v->push_back(swap(pos0, pos0 - 1, id));
    if (pos0 != N - 1)   v->push_back(swap(pos0, pos0 + 1, id));
  }
}

std::map<int, int> tbl;
std::queue<int> q;

int main() {
  int board[N];
  for (size_t i = 0; i < N; i++) board[i] = i;
  int id = get_id(board);

  q.push(id);
  tbl[id] = 0;
  while (!q.empty()) {
    id = q.front(); q.pop();
    int step = tbl[id];
    std::vector<int> v;
    next_ids(id, &v);
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
      if (tbl.find(*it) == tbl.end()) {
        q.push(*it);
        tbl[*it] = step + 1;
      }
    }
  }

  while(1){
    for(int i = 0; i < N; ++i){
      if(scanf("%d", &board[i]) == EOF){
        return 0;
      }
    }
    printf("%d\n", tbl[get_id(board)]);
  }
}

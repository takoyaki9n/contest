#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string line;
  std::cin >> line;
  int n = line.size();
  line[n-1] = '5';
  std::cout << line << std::endl;
}

#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  int grid[15][15]{0};
  rep(i, 15) {
    if (i % 2 == 1) continue;

    for (int j = 7 - abs(7 - i); j <= 7 + abs(7 - i); ++j) {
      grid[i][j] = 1;
      grid[j][i] = 1;
    }
  }

  // rep(i, 15) {
  //   printf("%2d ", i);
  //   rep(j, 15) cout << grid[i][j];
  //   cout << endl;
  // }

  string ans = grid[r - 1][c - 1] == 0 ? "white" : "black";
  cout << ans << endl;
  return 0;
}
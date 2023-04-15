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
  int h, w;
  cin >> h >> w;

  int **conv = new int *[h];
  rep(i, h) conv[i] = new int[w]{0};

  int **flag = new int *[h];
  rep(i, h) flag[i] = new int[w]{0};

  vector<pair<int, int>> direction = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

  rep(i, h) {
    rep(j, w) {
      char c;
      cin >> c;
      if (c == 'U')
        conv[i][j] = 0;
      else if (c == 'R')
        conv[i][j] = 1;
      else if (c == 'D')
        conv[i][j] = 2;
      else if (c == 'L')
        conv[i][j] = 3;
    }
  }

  int y = 0, x = 0;
  while (true) {
    if (flag[y][x] != 0) {
      cout << -1 << endl;
      return 0;
    }

    flag[y][x] = 1;

    // cout << "conv:" << conv[y][x] << " ";
    int yy = y + direction[conv[y][x]].second;
    int xx = x + direction[conv[y][x]].first;
    // cout << "yy:" << yy << " xx:" << xx << endl;
    if (0 <= yy && yy < h && 0 <= xx && xx < w) {
      y = yy;
      x = xx;
    } else {
      break;
    }
  }

  cout << y + 1 << " " << x + 1 << endl;

  return 0;
}
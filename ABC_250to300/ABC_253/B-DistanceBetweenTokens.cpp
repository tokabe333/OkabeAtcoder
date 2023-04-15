#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
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
  int sx = -1, sy = -1, gx, gy;
  rep(i, h) {
    string line;
    cin >> line;
    rep(j, w) {
      if (line[j] == 'o') {
        if (sx == -1) {
          sx = j;
          sy = i;
        } else {
          gx = j;
          gy = i;
        }
      }
    }
  }

  cout << abs(gx - sx) + abs(gy - sy) << endl;

  return 0;
}
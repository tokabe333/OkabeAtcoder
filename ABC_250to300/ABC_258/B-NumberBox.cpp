#include <string.h>

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

ll check(vector<vector<int>> &masu, int n, int sx, int sy, int dx, int dy) {
  ll ch = 0;

  rep(i, n) {
    int x = (sx + dx * i) % n;
    if (x < 0) x = n + x;
    int y = (sy + dy * i) % n;
    if (y < 0) y = n + y;
    ch += masu[y][x];
    ch *= 10;
  }
  return ch / 10;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> masu(n, vector<int>(n));
  rep(i, n) {
    string str;
    cin >> str;
    rep(j, n) masu[i][j] = str[j] - '0';
  }

  ll ans = -1;
  int d[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                 {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
  rep(i, n) {
    rep(j, n) {
      rep(k, 8) {
        ll cand = check(masu, n, i, j, d[k][0], d[k][1]);
        ans = max(ans, cand);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
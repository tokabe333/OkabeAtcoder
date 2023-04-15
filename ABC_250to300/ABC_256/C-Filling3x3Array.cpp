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

// 横(h)でチェックする
bool check(int **masu, int *h) {
  rep(i, 3) {
    int sum = 0;
    rep(j, 3) { sum += masu[i][j]; }
    if (sum != h[i]) return false;
  }
  return true;
}

ll make_v(int **masu, int *w, int j, int *h) {
  if (j == 3) {
    return check(masu, h) ? 1 : 0;
  }

  ll ans = 0;
  for (int i1 = 1; i1 <= w[j] - 2; ++i1) {
    masu[0][j] = i1;
    for (int i2 = 1; i2 <= w[j] - 2; ++i2) {
      masu[1][j] = i2;
      int i3 = w[j] - (i1 + i2);
      if (i3 < 1) break;
      masu[2][j] = i3;

      ans += make_v(masu, w, j + 1, h);
    }
  }
  return ans;
}

int main() {
  int *h = new int[3];
  int *w = new int[3];
  rep(i, 3) cin >> h[i];
  rep(i, 3) cin >> w[i];

  int **masu = new int *[3];
  rep(i, 3) masu[i] = new int[3]{0};

  // 縦(w)でパターンを作る
  cout << make_v(masu, w, 0, h) << endl;
  return 0;
}
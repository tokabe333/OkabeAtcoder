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

bool check(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2) { return true; }

int main() {
  ll h1, h2, w1, w2;
  cin >> h1 >> w1;

  vector<vector<ll>> mat1(h1, vector<ll>(w1, 0));
  rep(i, h1) {
    rep(j, w1) { scanf("%lld", &mat1[i][j]); }
  }

  cin >> h2 >> w2;
  vector<vector<ll>> mat2(h2, vector<ll>(w2, 0));
  rep(i, h2) {
    rep(j, w2) { scanf("%lld", &mat2[i][j]); }
  }

  // rep(i, h1) {
  //   printf("%2d ", i);
  //   rep(j, w1) printf("%3d ", mat1[i][j]);
  //   cout << endl;
  // }

  // 処理する順番に関わらず結果は同じになる

  return 0;
}
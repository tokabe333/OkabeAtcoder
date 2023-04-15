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
  ll n, m, k;
  ll MOD = 998244353;
  cin >> n >> m >> k;

  ll **dp = new ll *[k + 1];
  rep(i, k + 1) dp[i] = new ll[n + 1]{1};

  for (int y = 0; y <= k; ++y) {
    for (int x = 0; x < n; ++x) {
      for (int mm = 1; mm <= m; ++mm) {
        if (y + mm > k) continue;
        dp[y + mm][x + 1] = (dp[y + mm][x + 1] + dp[y][x]) % MOD;
      }
    }
  }

  // ll ans = 0;
  // for (int i = 0; i <= k; ++i) {
  //   ans += dp[i][n];
  // }
  // cout << ans << endl;
  cout << dp[k][n] << endl;
  return 0;
}
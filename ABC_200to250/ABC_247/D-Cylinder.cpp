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
  int q;
  cin >> q;

  queue<pair<ll, ll>> que;
  rep(_, q) {
    ll q, x, c;
    cin >> q;
    if (q == 1) {
      cin >> x >> c;
      if (que.size() == 0 || que.back().first != x) {
        que.push({x, c});
      } else {
        que.back().second += c;
      }
    }

    else {
      cin >> c;
      ll ans = 0;
      while (c > 0 && que.size() > 0) {
        ll f = que.front().first;
        ll s = que.front().second;
        ll cnt = min(c, s);
        c -= cnt;
        ans += cnt * f;
        que.front().second -= cnt;
        if (que.front().second == 0) que.pop();
      }
      cout << ans << endl;
    }
  }

  return 0;
}
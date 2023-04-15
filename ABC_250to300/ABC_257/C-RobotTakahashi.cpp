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
  int n, oya = 0;
  ll tmp;
  string s;
  cin >> n >> s;

  vector<pair<ll, int>> arr(n);
  rep(i, n) {
    scanf("%I64d", &tmp);
    arr[i] = {tmp, s[i] - '0'};
    if (arr[i].second == 1) oya += 1;
  }
  sort(arr.begin(), arr.end());

  int ans = oya;
  int res = oya;
  rep(i, n) {
    // 左から順に動かしていく
    // 最初は親がすべて正解，子供がすべて不正解
    // 左に子供を置くたびに＋1
    if (arr[i].second == 0)
      res += 1;
    else
      res -= 1;

    if (i < n - 1 && arr[i].first != arr[i + 1].first) ans = max(ans, res);
  }
  ans = max(ans, res);

  cout << ans << endl;
  return 0;
}
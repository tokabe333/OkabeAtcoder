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
  int n;
  cin >> n;
  vector<pair<int, int>> lr(n);
  rep(i, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    lr[i] = {l, r};
  }
  sort(lr.begin(), lr.end());

  vector<pair<int, int>> ans;
  int minleft = lr[0].first;
  int maxright = lr[0].second;

  for (int i = 1; i < n; ++i) {
    int l = lr[i].first;
    int r = lr[i].second;

    if (l > maxright) {
      ans.emplace_back(pair<int, int>{minleft, maxright});
      minleft = l;
      maxright = r;
      continue;
    }
    if (maxright < r) maxright = r;
  }
  ans.emplace_back(pair<int, int>{minleft, maxright});

  rep(i, ans.size()) { cout << ans[i].first << " " << ans[i].second << endl; }

  return 0;
}
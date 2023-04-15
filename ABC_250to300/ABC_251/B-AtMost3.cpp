#include <algorithm>
#include <cmath>
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
  int n, w;
  cin >> n >> w;
  ll *arr = new ll[n];
  rep(i, n) cin >> arr[i];
  bool *flag = new bool[w + 1]{false};

  for (int i = 0; i < n; ++i) {
    if (arr[i] <= w) flag[arr[i]] = true;
    for (int j = i + 1; j < n; ++j) {
      if (j >= n) break;
      ll ij = arr[i] + arr[j];
      if (ij <= w) flag[ij] = true;

      for (int k = j + 1; k < n; ++k) {
        if (k >= n) break;
        ll ijk = ij + arr[k];
        if (ijk <= w) flag[ijk] = true;
      }
    }
  }

  ll ans = 0;
  rep(i, w + 1) {
    if (flag[i] == true) {
      ans += 1;
      // cout  << i << endl;
    }
  }
  cout << ans << endl;

  return 0;
}
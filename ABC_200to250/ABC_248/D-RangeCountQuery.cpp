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
  int n;
  cin >> n;
  int *arr = new int[n];
  vector<vector<int>> vec(n + 1);
  rep(i, n) {
    scanf("%d", &arr[i]);
    vec[arr[i]].emplace_back(i);
  }

  int q;
  cin >> q;
  rep(qq, q) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);

    auto li = lower_bound(vec[x].begin(), vec[x].end(), l - 1);
    auto ri = lower_bound(vec[x].begin(), vec[x].end(), r);
    cout << ri - li << endl;
  }

  return 0;
}
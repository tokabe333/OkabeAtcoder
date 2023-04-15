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
  int h, w, r, c;
  cin >> h >> w >> r >> c;

  int ans = 0;
  if (r < h) ans += 1;
  if (1 < r) ans += 1;
  if (c < w) ans += 1;
  if (1 < c) ans += 1;
  cout << ans << endl;

  return 0;
}
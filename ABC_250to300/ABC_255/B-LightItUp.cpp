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
  int n, k;
  cin >> n >> k;

  unordered_map<int, bool> hash;
  rep(i, k) {
    int tmp;
    scanf("%d", &tmp);
    hash[tmp - 1] = true;
  }

  int **xy = new int *[n];
  rep(i, n) {
    xy[i] = new int[2];
    scanf("%d %d", &xy[i][0], &xy[i][1]);
  }

  double ans = 0;
  // –¾‚©‚è‚ðŽ‚Á‚Ä‚È‚¢l‚©‚çŒ©‚é‚¾‚¯
  rep(i, n) {
    if (hash.find(i) != hash.end()) continue;
    int x = xy[i][0];
    int y = xy[i][1];
    double tmp = pow(10, 16);

    for (auto itr = hash.begin(); itr != hash.end(); itr++) {
      int xx = xy[itr->first][0];
      int yy = xy[itr->first][1];
      double d = pow(xx - x, 2) + pow(yy - y, 2);

      // cout << "i:" << i << " key=" << itr->first;
      // printf("x:%d y:%d xx:%d yy:%d d:%lf\n", x, y, xx, yy, d);
      tmp = min(tmp, d);
    }
    ans = max(ans, tmp);
  }
  printf("%.10lf\n", sqrt(ans));

  return 0;
}
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
  int n;
  cin >> n;
  // 0~9‚Ì”š‚ª0~9•b‚ÌŠÔ‚Å‰½‰ñoŒ»‚µ‚Ä‚¢‚é‚©
  vector<vector<int>> zikan(10, vector<int>(10, 0));
  rep(i, n) {
    string str;
    cin >> str;
    rep(j, 10) { zikan[str[j] - '0'][j] += 1; }
  }

  int ans = pow(10, 8);
  rep(i, 10) {
    int time = -1;
    int j = 9;
    int cnt = 0;
    while (cnt < n) {
      j = (j + 1) % 10;
      time += 1;
      if (zikan[i][j] == 0) continue;
      zikan[i][j] -= 1;
      cnt += 1;
    }
    ans = min(ans, time);
  }
  cout << ans << endl;

  return 0;
}
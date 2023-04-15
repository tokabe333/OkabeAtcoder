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
  ll n, sx, sy, tx, ty;
  cin >> n >> sx >> sy >> tx >> ty;

  vector<vector<ll>> arr(n, vector<ll>(3));
  rep(i, n) { scanf("%lld %lld %lld", &arr[i][0], &arr[i][1], &arr[i][2]); }

  vector<vector<int>> mat(n);

  rep(i, n - 1) {
    for (int j = i + 1; j < n; ++j) {
      ll d = pow(arr[i][0] - arr[j][0], 2) + pow(arr[i][1] - arr[j][1], 2);
      ll r1 = arr[i][2];
      ll r2 = arr[j][2];

      if (pow(r1 + r2, 2) < d) continue;  //ó£ÇÍÇƒÇÈ
      if (pow(r1 - r2, 2) > d) continue;  //ì‡ïÔ
      mat[i].emplace_back(j);
      mat[j].emplace_back(i);
    }
  }

  // ÉXÉ^Å[ÉgÇ∆ÉSÅ[ÉãÇÃâ~ÇíTÇ∑
  int s = -1, t = -1;
  rep(i, n) {
    ll x = arr[i][0];
    ll y = arr[i][1];
    ll r = arr[i][2];
    if (round(pow(x - sx, 2) + pow(y - sy, 2)) == round(pow(r, 2))) {
      s = i;
    }

    if (round(pow(x - tx, 2) + pow(y - ty, 2)) == round(pow(r, 2))) {
      t = i;
    }
  }

  queue<int> que;
  bool* flag = new bool[n + 1]{false};
  que.push(s);
  flag[s] = true;
  while (que.empty() == false) {
    int current = que.front();
    que.pop();

    if (current == t) {
      cout << "Yes" << endl;
      return 0;
    }

    rep(i, mat[current].size()) {
      int next = mat[current][i];
      if (flag[next] == false) {
        que.push(next);
        flag[current] = true;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
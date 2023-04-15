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
  ll MAX = 200000;
  ll n;
  cin >> n;
  ll *arr = new ll[n];
  ll *counts = new ll[MAX]{0};
  rep(i, n) {
    ll tmp;
    scanf("%lld", &tmp);
    arr[i] = tmp;
    counts[tmp] += 1;
  }

  vector<vector<ll>> eratos(MAX + 1, vector<ll>(0));
  for (int i = 1; i <= MAX; ++i) {
    for (int j = i + i; j <= MAX; j += i) {
      // if (i * i <= j)
      eratos[j].emplace_back(i);
    }
    eratos[i].emplace_back(i);
  }

  // rep(i, 30) {
  //   cout << "i:" << i << " ";
  //   rep(j, eratos[i].size()) cout << eratos[i][j] << " ";
  //   cout << endl;
  // }

  ll ans = 0;
  rep(i, n) {
    ll a = arr[i];
    rep(j, eratos[a].size()) {
      ll b = eratos[a][j];
      ll bn = counts[b];

      ll c = a / b;
      ll cn = counts[c];

      ans += bn * cn;
    }
  }
  cout << ans << endl;

  return 0;
}
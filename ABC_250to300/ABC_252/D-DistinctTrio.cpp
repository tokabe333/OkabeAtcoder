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
  ll n;
  cin >> n;
  unordered_map<int, int> hash;
  rep(i, n) {
    int tmp;
    scanf("%d", &tmp);
    if (hash.find(tmp) == hash.end())
      hash[tmp] = 1;
    else
      hash[tmp] += 1;
  }

  ll ans = n * (n - 1) * (n - 2) / 6;

  // 同じ数字の個数で分けて考える
  for (auto itr = hash.begin(); itr != hash.end(); itr++) {
    ll x = itr->first;
    ll num = itr->second;

    if (num <= 1) {
      continue;
    } else if (num == 2) {
      ans -= (n - 2);  // x以外から選択する
    } else if (num == 3) {
      ans -= 1;              // (i,j,k)
      ans -= (3 * (n - 3));  // 2つ選んで残りをx以外から1つ
    } else {
      ans -= (num * (num - 1) * (num - 2) / 6);  // xから3つ選択
      ans -= ((num * (num - 1) / 2) * (n - num));  // xから2つ　残りから1つ選択
    }
  }
  cout << ans << endl;

  return 0;
}
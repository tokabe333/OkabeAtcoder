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
  ll n, p, q, r;
  cin >> n >> p >> q >> r;

  ll *arr = new ll[n];
  rep(i, n) scanf("%lld", &arr[i]);

  unordered_map<ll, int> hash;
  ll *prefix = new ll[n];
  prefix[0] = arr[0];
  hash[arr[0]] = 0;
  for (int i = 1; i < n; ++i) {
    prefix[i] += prefix[i - 1] + arr[i];
    hash[prefix[i]] = i;
  }

  rep(i, n) { cout << "i:" << i << " value:" << prefix[i] << endl; }
  cout << endl;
  for (auto itr = hash.begin(); itr != hash.end(); itr++) {
    cout << "key:" << itr->first << " value:" << itr->second << endl;
  }

  vector<pair<int, int>> candp, candq, candr;
  rep(i, n) {
    auto f = hash.find(p - prefix[i]);
    if (f != hash.end()) candp.emplace_back(pair{i, f->second});
  }

  cout << candp.size() << endl;
  rep(i, candp.size()) {
    cout << candp[i].first << " " << candp[i].second << endl;
  }

  return 0;
}
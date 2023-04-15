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
  int q;
  cin >> q;

  unordered_map<ll, ll> hash;
  ll _min = pow(10, 10);
  ll _max = 0;
  rep(i, q) {
    ll n, x, c;
    cin >> n;
    if (n == 1) {
      cin >> x;
      if (hash.find(x) == hash.end()) {
        hash[x] = 1;
        _max = max(_max, x);
        _min = min(_min, x);
      } else {
        hash[x] += 1;
      }
    } else if (n == 2) {
      cin >> x >> c;
      if (hash.find(x) == hash.end()) continue;
      if (hash[x] <= c) {
        hash.erase(x);
        if (x != _max && x != _min) continue;
        _max = 0;
        _min = pow(10, 10);
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
          _max = max(_max, itr->first);
          _min = min(_min, itr->first);
        }
      } else {
        hash[x] -= c;
      }
    } else {
      cout << _max - _min << endl;
    }
  }

  return 0;
}
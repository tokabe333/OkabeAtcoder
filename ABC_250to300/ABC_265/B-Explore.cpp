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
  ll n, m, t;
  cin >> n >> m >> t;

  ll *arr = new ll[n]{0};
  ll *brr = new ll[n]{0};

  rep(i, n - 1) scanf("%lld", &arr[i]);
  rep(i, m) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    brr[a - 2] += b;
  }

  rep(i, n) {
    // cout << "a:" << arr[i] << " b:" << brr[i] << " t:" << t << endl;

    t -= arr[i];
    if (t <= 0) {
      cout << "No" << endl;
      return 0;
    }
    t += brr[i];
  }
  cout << "Yes" << endl;

  return 0;
}
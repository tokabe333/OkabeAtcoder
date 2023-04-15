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
  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d == 0) {
    cout << abs(x - a) << endl;
    return 0;
  }
  if (d < 0) {
    d *= -1;
    a = a - (d * (n - 1));
  }

  if (x <= a) {
    cout << abs(x - a) << endl;
    return 0;
  }
  if (a + d * (n - 1) <= x) {
    cout << abs(x - (a + d * (n - 1))) << endl;
    return 0;
  }

  ll cand = (x - a) % d;
  cout << min(cand, d - cand) << endl;

  return 0;
}
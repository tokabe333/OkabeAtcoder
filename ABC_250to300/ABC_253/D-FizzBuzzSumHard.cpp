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

ll GCD(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  while (a != 0 && b != 0) {
    if (a > b)
      a = a % b;
    else
      b = b % a;
  }
  return max(a, b);
}

ll LCM(ll a, ll b) {
  if (a == 0 || b == 0) return 0;
  return a * b / GCD(a, b);
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll ans = n * (n + 1) / 2;
  ans -= (n / a) * (2 * a + (n / a - 1) * a) / 2;
  ans -= (n / b) * (2 * b + (n / b - 1) * b) / 2;
  ll l = lcm(a, b);
  ans += (n / l) * (2 * l + (n / l - 1) * l) / 2;

  cout << ans << endl;

  return 0;
}
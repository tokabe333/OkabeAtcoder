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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  ll cnt = 0;
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    if (p == 2) {
      x -= 1;
      x = (x - cnt) % n;
      if (x < 0) x = n + x;
      cout << s[x] << endl;
    } else {
      cnt = (cnt + x) % n;
    }
  }

  return 0;
}
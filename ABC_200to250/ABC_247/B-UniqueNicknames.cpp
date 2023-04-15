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
  int n;
  cin >> n;
  vector<string> sei(n), mei(n);
  rep(i, n) cin >> sei[i] >> mei[i];

  rep(i, n) {
    bool s = true, m = true;
    rep(j, n) {
      if (i == j) continue;
      if (sei[i] == sei[j] || sei[i] == mei[j]) s = false;
      if (mei[i] == sei[j] || mei[i] == mei[j]) m = false;
    }
    if (s == false && m == false) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
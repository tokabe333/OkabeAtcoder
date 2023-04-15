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
  int n;
  cin >> n;
  unordered_map<string, bool> hash;
  ll maxPoint = 0;
  ll ans;

  string str;
  ll t;
  rep(i, n) {
    cin >> str >> t;
    if (hash.find(str) != hash.end()) continue;
    hash[str] = true;
    if (t > maxPoint) {
      maxPoint = t;
      ans = i;
    }
  }
  cout << ans + 1 << endl;

  return 0;
}
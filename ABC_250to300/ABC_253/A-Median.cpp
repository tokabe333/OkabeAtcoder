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
  int a, b, c;
  cin >> a >> b >> c;

  string ans = (a <= b && b <= c) || (c <= b && b <= a) ? "Yes" : "No";
  cout << ans << endl;

  return 0;
}
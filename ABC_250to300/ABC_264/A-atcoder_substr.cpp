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
  int l, r;
  cin >> l >> r;

  string str = "atcoder";
  for (int i = l - 1; i < r; ++i) {
    cout << str[i];
  }
  cout << endl;

  return 0;
}
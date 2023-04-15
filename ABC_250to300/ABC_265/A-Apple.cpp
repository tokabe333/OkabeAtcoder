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
  int x, y, n;
  cin >> x >> y >> n;

  if (x * 3 <= y) {
    cout << x * n << endl;
  } else {
    cout << (n / 3) * y + (n % 3) * x << endl;
  }

  return 0;
}
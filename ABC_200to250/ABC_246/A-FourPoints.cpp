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
  int x[3], y[3];
  rep(i, 3) { cin >> x[i] >> y[i]; }

  if (x[0] == x[1]) cout << x[2] << " ";
  if (x[1] == x[2]) cout << x[0] << " ";
  if (x[2] == x[0]) cout << x[1] << " ";

  if (y[0] == y[1]) cout << y[2] << endl;
  if (y[1] == y[2]) cout << y[0] << endl;
  if (y[2] == y[0]) cout << y[1] << endl;

  return 0;
}
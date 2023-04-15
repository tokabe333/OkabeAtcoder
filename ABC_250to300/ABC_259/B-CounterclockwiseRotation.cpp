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
  int a, b, d;
  cin >> a >> b >> d;

  double th = atan2(b, a);
  th = th + d / 180.0 * PI;
  double r = sqrt(a * a + b * b);

  cout << fixed << setprecision(10) << r * cos(th) << " " << r * sin(th)
       << endl;
}
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
  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int takahashi = (x / (a + c) * a * b) + (min(x % (a + c), a) * b);
  int aoki = (x / (d + f) * d * e) + (min(x % (d + f), d) * e);

  // cout << " t:" << (x / (a + c) * a * b) << " t2:" << min(x % (a + c), a) * b
  //      << endl;
  // cout << "takahashi:" << takahashi << " aoki:" << aoki << endl;

  if (takahashi > aoki)
    cout << "Takahashi" << endl;
  else if (takahashi == aoki)
    cout << "Draw" << endl;
  else
    cout << "Aoki" << endl;

  return 0;
}
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
  int w;
  cin >> w;
  cout << 99 * 3 << endl;
  for (int i = 1; i <= 99; ++i) cout << i << " ";
  for (int i = 100; i <= 9900; i += 100) cout << i << " ";
  for (int i = 10000; i <= 990000; i += 10000) cout << i << " ";
  cout << endl;

  return 0;
}
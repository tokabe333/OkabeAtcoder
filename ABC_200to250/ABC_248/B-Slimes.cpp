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
  ll a, b, k;
  cin >> a >> b >> k;

  int count = 0;
  while (a < b) {
    a *= k;
    count += 1;
  }
  cout << count << endl;

  return 0;
}
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  int n, m, x, t, d;
  cin >> n >> m >> x >> t >> d;

  if (m <= x) {
    cout << t - d * (x - m) << endl;
  } else {
    cout << t << endl;
  }

  return 0;
}
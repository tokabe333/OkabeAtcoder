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
  int n;
  cin >> n;
  int *prr = new int[n]{0};
  for (int i = 1; i < n; ++i) cin >> prr[i];
  for (int i = 1; i < n; ++i) prr[i] -= 1;

  int current = n - 1;
  int cnt = 0;
  while (current != 0) {
    current = prr[current];
    cnt += 1;
  }

  cout << cnt << endl;

  return 0;
}
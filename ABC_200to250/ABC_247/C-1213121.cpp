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

  int num = pow(2, n) - 1;
  int *arr = new int[num];
  rep(i, num) arr[i] = 1;

  for (int i = 2; i <= n; i += 1) {
    int diff = pow(2, i - 1);
    for (int j = diff - 1; j < num; j += diff) {
      arr[j] += 1;
    }
    // rep(i, num) cout << arr[i] << " ";
    // cout << endl;
  }

  rep(i, num) cout << arr[i] << " ";
  cout << endl;

  return 0;
}
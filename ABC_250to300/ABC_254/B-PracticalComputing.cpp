#include <algorithm>
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
  int n;
  cin >> n;
  int *arr = new int[1]{0};
  int *prev = new int[1]{1};
  cout << 1 << endl;

  for (int i = 1; i < n; ++i) {
    arr = new int[i + 1];
    arr[0] = 1;
    for (int j = 1; j < i; ++j) {
      arr[j] = prev[j] + prev[j - 1];
    }
    arr[i] = 1;
    rep(j, i + 1) cout << arr[j] << " ";
    cout << endl;
    prev = arr;
  }

  return 0;
}
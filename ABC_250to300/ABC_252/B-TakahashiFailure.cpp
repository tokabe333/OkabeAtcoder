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
  int n, k;
  cin >> n >> k;
  int *arr = new int[n];
  int *brr = new int[k];
  rep(i, n) cin >> arr[i];
  rep(i, k) cin >> brr[i];

  int _max = 0;
  rep(i, n) { _max = max(_max, arr[i]); }

  rep(i, k) {
    if (arr[brr[i] - 1] == _max) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
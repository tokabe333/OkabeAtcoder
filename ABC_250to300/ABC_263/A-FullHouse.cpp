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
  vector<int> arr(5);
  rep(i, 5) cin >> arr[i];

  sort(arr.begin(), arr.end());

  if (arr[0] == arr[1] && arr[1] == arr[2] && arr[3] == arr[4] ||
      arr[0] == arr[1] && arr[2] == arr[3] && arr[3] == arr[4])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
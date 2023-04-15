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
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> arr(k);
  rep(i, k) scanf("%d", &arr[i]);
  sort(arr.begin(), arr.end());

  rep(i, q) {
    int l;
    scanf("%d", &l);
    l -= 1;

    if (arr[l] == n || arr[l] + 1 == arr[l + 1]) continue;
    arr[l] += 1;
  }

  rep(i, k) cout << arr[i] << " ";
  cout << endl;

  return 0;
}
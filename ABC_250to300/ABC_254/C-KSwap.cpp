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
  int n, k;
  cin >> n >> k;
  ll *arr = new ll[n];
  rep(i, n) scanf("%lld", &arr[i]);

  rep(i, k) {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int j = i; j < n; j += k) {
      pq.push(arr[j]);
    }

    for (int j = i; j < n; j += k) {
      arr[j] = pq.top();
      pq.pop();
    }
  }
  ll prev = arr[0];
  for (int i = 1; i < n; ++i) {
    if (arr[i] < prev) {
      cout << "No" << endl;
      return 0;
    }
    prev = arr[i];
  }
  cout << "Yes" << endl;

  return 0;
}
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
  int n, q;
  cin >> n >> q;
  int *ball = new int[n];
  rep(i, n) ball[i] = i + 1;
  unordered_map<int, int> hash;
  rep(i, n) hash[i + 1] = i;

  rep(i, q) {
    int x;
    cin >> x;

    int index = hash[x];
    int rightIndex = index < n - 1 ? index + 1 : n - 2;
    int right = ball[rightIndex];

    hash[x] = rightIndex;
    hash[right] = index;
    ball[index] = right;
    ball[rightIndex] = x;

    // rep(i, n) cout << ball[i] << " ";
    // cout << endl;
  }

  rep(i, n) cout << ball[i] << " ";
  cout << endl;
  return 0;
}
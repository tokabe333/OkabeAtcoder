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
  string str;
  cin >> str;

  bool up = false;
  bool low = false;
  int *arr = new int[1000]{0};

  rep(i, str.size()) {
    char c = str[i];
    if ('A' <= c && c <= 'Z') up = true;
    if ('a' <= c && c <= 'z') low = true;
    arr[(int)c] += 1;
    // cout << "i:" << i << " c:" << c << " nm:" << (int)c
    //      << " arr:" << arr[(int)c] << endl;
    if (arr[(int)c] > 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (up && low) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
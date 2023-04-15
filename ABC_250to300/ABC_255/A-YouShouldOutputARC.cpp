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
  int r, c;
  cin >> r >> c;
  int masu[2][2];
  rep(i, 2) {
    rep(j, 2) { cin >> masu[i][j]; }
  }

  cout << masu[r - 1][c - 1] << endl;

  return 0;
}
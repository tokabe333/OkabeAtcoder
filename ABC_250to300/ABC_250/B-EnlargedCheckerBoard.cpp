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
  int n, a, b;
  cin >> n >> a >> b;

  string str = ".#";
  rep(i, n) {
    rep(y, a) {
      rep(j, n) {
        if ((i + j) % 2 == 0) {
          rep(x, b) cout << ".";
        } else {
          rep(x, b) cout << "#";
        }
      }
      cout << endl;
    }
  }

  return 0;
}
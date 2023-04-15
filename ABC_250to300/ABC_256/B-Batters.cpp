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
  int *arr = new int[n];
  rep(i, n) scanf("%d", &arr[i]);
  bool *masu = new bool[4]{false};
  int p = 0;

  rep(i, n) {
    masu[0] = true;
    for (int j = 3; j >= 0; j -= 1) {
      if (masu[j] == true) {
        if (j + arr[i] > 3) {
          masu[j] = false;
          p += 1;
        } else {
          masu[j] = false;
          masu[j + arr[i]] = true;
        }
      }
    }
    // cout << "p:" << p << " masu:";
    // rep(j, 4) cout << masu[j] << " ";
    // cout << endl;
  }
  cout << p << endl;

  return 0;
}
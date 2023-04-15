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
  int k;
  cin >> k;

  cout << setfill('0') << right << setw(2) << (21 + k / 60) % 24 << ":"
       << setfill('0') << right << setw(2) << k % 60 << endl;

  return 0;
}
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

vector<pair<char, int>> MakeArr(string s) {
  vector<pair<char, int>> arr{{'|', 0}};
  for (char c : s) {
    if (c != arr.back().first) {
      arr.emplace_back(c, 1);
    } else {
      arr.back().second += 1;
    }
  }
  arr.erase(arr.begin());
  return arr;
}

int main() {
  string s, t;
  cin >> s >> t;

  auto sarr = MakeArr(s);
  auto tarr = MakeArr(t);

  if (sarr.size() != tarr.size()) {
    cout << "No" << endl;
    return 0;
  }

  rep(i, sarr.size()) {
    char s1 = sarr[i].first;
    int s2 = sarr[i].second;
    char t1 = tarr[i].first;
    int t2 = tarr[i].second;

    // printf("%c %d %c %d\n", s1, s2, t1, t2);

    bool f1 = s1 != t1;
    bool f2 = (s2 == 1 && t2 > 1);
    bool f3 = s2 > t2;
    if (f1 || f2 || f3) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
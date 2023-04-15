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
  string str;
  cin >> str;

  unordered_map<char, int> hash{{'a', 0}, {'t', 1}, {'c', 2}, {'o', 3},
                                {'d', 4}, {'e', 5}, {'r', 6}};

  int *arr = new int[str.size()];
  rep(i, str.size()) arr[i] = hash[str[i]];

  int count = 0;
  rep(i, str.size() - 1) {
    for (int j = i + 1; j < str.size(); ++j) {
      if (arr[i] > arr[j]) {
        char hoge = arr[i];
        arr[i] = arr[j];
        arr[j] = hoge;
        count += 1;
      }
    }
  }

  cout << count << endl;

  return 0;
}
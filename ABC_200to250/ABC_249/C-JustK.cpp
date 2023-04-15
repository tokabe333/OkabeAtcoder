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

void recursive_comb(int *indexes, int s, int rest,
                    std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCk‚Ì‘g‚Ý‡‚í‚¹‚É‘Î‚µ‚Äˆ—‚ðŽÀs‚·‚é
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  vector<string> strs(n);
  rep(i, n) { cin >> strs[i]; }

  for (int i = 1; i <= n; ++i) {
    foreach_comb(n, i, [&i, &k, &ans, &strs](int *indexes) {
      int *counts = new int[30]{0};
      rep(j, i) {
        string str = strs[indexes[j]];
        rep(k, str.size()) { counts[str[k] - 'a'] += 1; }
      }

      int count = 0;
      rep(j, 27) {
        if (counts[j] == k) count += 1;
      }
      ans = max(ans, count);
    });
  }
  cout << ans << endl;

  return 0;
}
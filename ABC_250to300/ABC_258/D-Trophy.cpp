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
  int n, x;
  cin >> n >> x;
  vector<vector<ll>> arr(n, vector<ll>(2));
  rep(i, n) { scanf("%lld %lld", &arr[i][0], &arr[i][1]); }

  ll ans = arr[0][0] + arr[0][1] * x;
  ll sum2i = arr[0][0] + arr[0][1];
  ll mintime = arr[0][1];
  for (int i = 1; i < n; ++i) {
    sum2i += arr[i][0] + arr[i][1];
    // i”Ô–Ú‚ÌƒQ[ƒ€ƒvƒŒƒCŽžŠÔ‚ª’·‚¢‚È‚çi-1‚Ü‚Å‚Ì”ÍˆÍ‚Å—V‚ñ‚¾‚Ù‚¤‚ª“¾
    if (mintime <= arr[i][1]) continue;

    // ‚»‚¤‚Å‚È‚¢‚È‚çŒvŽZ‚·‚é
    ll cand = sum2i + arr[i][1] * (x - i - 1);
    if (cand < ans) {
      mintime = arr[i][1];
      ans = cand;
    }
  }

  cout << ans << endl;
  return 0;
}
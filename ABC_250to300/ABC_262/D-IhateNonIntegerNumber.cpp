#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
// #define mod998 998244353

typedef long long int                  ll;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
typedef vector<float>                  vf;
typedef vector<vector<float>>          vvf;
typedef vector<vector<vector<float>>>  vvvf;
typedef vector<double>                 vd;
typedef vector<vector<double>>         vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef pair<ll, ll>                   pii;
typedef pair<ll, string>               pis;
typedef pair<string, ll>               psi;

int main() {
    ll n;
    cin >> n;
    vll arr(n);
    rep(i, n) scanf("%lld", &arr[i]);

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        vvvll dp(n + 1, vvll(i + 1, vll(i, 0)));
        dp[0][0][0] = 1;

        for (int j = 0; j < n; ++j) {
            for (int k = 0; k <= i; ++k) {
                for (int l = 0; l < i; ++l) {
                    // 選ばないパターン
                    dp[j + 1][k][l] = mod998(dp[j + 1][k][l] + dp[j][k][l]);
                    // 選ぶパターｎ
                    if (k >= i) continue;
                    // cout << "i:" << i << " j:" << j << " k:" << k << " l:" << l << endl;
                    ll hoge = dp[j + 1][k + 1][(l + arr[j]) % i];
                    // cout << "hoge:" << hoge << "dp:" << dp[j][k][l] << endl;
                    dp[j + 1][k + 1][(l + arr[j]) % i] = mod998(dp[j][k][l] + hoge);
                }
            }
        }
        // cout << " ans:" << ans << endl;
        ans = ans + mod998(dp[n][i][0]);
    }

    cout << mod998(ans) << endl;

    return 0;
}
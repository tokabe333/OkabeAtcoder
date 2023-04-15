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
    ll  hoge;
    rep(i, n) {
        scanf("%lld", &hoge);
        arr[i] = hoge % 200;
    }

    vvvi dp(200, vvi(n + 1, vi(0)));
    dp[arr[0]][0].emplace_back(arr[0]);

    for (int j = 0; j < n - 1; ++j) {
        // ‰¡
        rep(i, 200) {
            if (dp[i][j].size() == 0) continue;
            dp[i][j + 1] = vi(dp[i][j]);
        }

        // ŽÎ‚ß
        rep(i, 200) {
            if (dp[i][j].size() == 0) continue;
            int next_y = (arr[j] + i) % 200;
            if (dp[next_y][j + 1].size() != 0) {
                cout << "Yes" << endl;
                rep(k, dp[next_y][j + 1].size()) cout << dp[next_y][j + 1][k] << " ";
                cout << endl;

                rep(k, dp[i][j].size()) cout << dp[i][j][k] << " ";
                cout << arr[j] << endl;
                return 0;
            }

            dp[next_y][j + 1] = vi(dp[i][j]);
            dp[next_y][j + 1].emplace_back(arr[j]);
        }
    }

    rep(i, 200) {
        rep(j, n + 1) {
            cout << dp[i][j].size() << " ";
        }
        cout << endl;
    }

    cout << "No" << endl;

    return 0;
}
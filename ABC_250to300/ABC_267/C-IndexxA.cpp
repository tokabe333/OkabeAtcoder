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
#include <set>
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
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;

int main() {
    bool debug = true;
    ll   n, m;
    cin >> n >> m;
    vi arr(n);
    rep(i, n) cin >> arr[i];

    vll ruisekiwa(n + 1);
    for (int i = 1; i <= n; ++i) {
        ruisekiwa[i] = ruisekiwa[i - 1] + arr[i - 1];
    }

    ll  ans = -1 * pow(2, sizeof(ll) * 8 - 1);
    ll  num = 1;
    vll cand(n + 1, 0);
    rep(i, m) num += (i + 1) * arr[i];
    for (int i = 1; i <= n - m; ++i) {
        cand[i] = cand[i - 1] + m * arr[m + i - 1] - ruisekiwa[m + i - 1] + ruisekiwa[i - 1];
    }

    rep(i, n + 1) {
        ans = max(ans, cand[i]);
    }

    cout << ans << endl;

    return 0;
}
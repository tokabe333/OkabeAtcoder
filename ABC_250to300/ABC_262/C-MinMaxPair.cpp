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
    vi  arr(n);
    int hoge;
    rep(i, n) {
        scanf("%d", &hoge);
        arr[i] = hoge - 1;
    }
    int    onazi = 0;
    double ans   = 0;
    rep(i, n) {
        if (i == arr[i]) {
            ans += onazi;
            onazi += 1;
            // cout << "i:" << i << " onazi:" << onazi << " ans:" << ans << endl;
        } else if (arr[arr[i]] == i) {
            ans += 0.5;
            // cout << "i:" << i << " ans:" << ans << endl;
        }
        // if (i % 1000 == 0) cout << "i:" << i << " ans:" << ans << endl;
    }
    cout << (ll)ans << endl;
    return 0;
}
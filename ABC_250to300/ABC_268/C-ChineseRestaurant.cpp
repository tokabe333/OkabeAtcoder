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

int modmod(int a, int mod) {
    int b = a % mod;
    if (b < 0) b += mod;
    return b;
}

int main() {
    ll n;
    cin >> n;
    vi arr(n);
    rep(i, n) cin >> arr[i];

    vi sabun(n, 0);
    rep(i, n) {
        int sa = arr[i] - i;
        if (sa < 0) sa += n;
        sabun[modmod(sa - 1, n)] += 1;
        sabun[sa] += 1;
        sabun[modmod(sa + 1, n)] += 1;
    }

    // rep(i, n) cout << sabun[i] << " ";
    // cout << endl;

    cout << *max_element(sabun.begin(), sabun.end()) << endl;

    return 0;
}
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
    rep(i, n) scanf("%lld", &arr[i]);

    unordered_map<ll, ll> hash;
    rep(i, n) {
        int mod = arr[i] % 200;
        if (hash.find(mod) != hash.end())
            hash[mod] += 1;
        else
            hash[mod] = 1;
    }

    ll ans = 0;
    for (auto itr = hash.begin(); itr != hash.end(); itr++) {
        ans += itr->second * (itr->second - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
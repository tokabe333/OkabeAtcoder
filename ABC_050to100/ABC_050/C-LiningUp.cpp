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
    vi arr(n);
    rep(i, n) scanf("%d", &arr[i]);

    unordered_map<int, int> hash;
    rep(i, n) {
        if (hash.find(arr[i]) != hash.end())
            hash[arr[i]] += 1;
        else
            hash[arr[i]] = 1;
    }

    // —áŠO
    for (auto itr = hash.begin(); itr != hash.end(); itr++) {
        if (itr->first != 0 && itr->second % 2 == 1) {
            cout << 0 << endl;
            return 0;
        }
        if (itr->first == 0) {
            if (n % 2 == 1 && itr->second % 2 == 0) {
                cout << 0 << endl;
                return 0;
            }
            if (n % 2 == 0 && itr->second % 2 == 1) {
                cout << 0 << endl;
                return 0;
            }
        }
    }

    if (n % 2 == 1) n -= 1;
    ll ans = 1;
    rep(i, n / 2) {
        ans = mod107(ans * 2);
    }

    cout << ans << endl;

    return 0;
}
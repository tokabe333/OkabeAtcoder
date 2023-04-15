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

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int              ll;
typedef vector<ll>                 vll;
typedef vector<vector<ll>>         vvll;
typedef vector<vector<vector<ll>>> vvvll;

int main() {
    ll n, q;
    cin >> n >> q;

    vvll mat(n, vll(0));
    rep(i, n) {
        ll l, t;
        cin >> l;
        rep(j, l) {
            cin >> t;
            mat[i].emplace_back(t);
        }
    }

    rep(i, q) {
        ll s, t;
        cin >> s >> t;
        cout << mat[s - 1][t - 1] << endl;
    }

    return 0;
}
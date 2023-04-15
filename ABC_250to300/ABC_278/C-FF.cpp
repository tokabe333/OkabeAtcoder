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

int main() {
    bool debug = false;
    ll   n, q;
    cin >> n >> q;

    set<pii> dict;

    int t, a, b;
    rep(i, q) {
        scanf("%d %d %d", &t, &a, &b);
        //  if(debug)
        // for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
        //     cout << (*itr).first << "-" << (*itr).second << " ";
        // }
        // cout << endl;

        if (t == 1) {
            dict.insert(pii(a, b));
        } else if (t == 2) {
            dict.erase(pii(a, b));
        } else {
            if (dict.count(pii(a, b)) == 1 && dict.count(pii(b, a)) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
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
    bool debug = false;
    ll   n, m;
    cin >> n >> m;

    unordered_map<int, vi> hash;
    set<int>               st;
    ll                     sum_arr = 0;
    int                    hoge;
    rep(i, n) {
        cin >> hoge;
        st.insert(hoge);
        if (hash.find(hoge) == hash.end()) {
            hash[hoge] = vi(1, hoge);
        } else {
            hash[hoge].emplace_back(hoge);
        }
        sum_arr += hoge;
    }

    if (debug) {
        for (auto itr = st.begin(); itr != st.end(); ++itr) {
            cout << *itr << " -- ";
            rep(i, hash[*itr].size()) {
                cout << hash[*itr][i] << " ";
            }
            cout << endl;
        }
        cout << "sum:" << sum_arr << endl;
    }

    ll   ans         = sum_arr;
    int  prev        = *st.begin() - 1;
    ll   current_sum = 0;
    auto beg_itr     = st.end();
    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        if (*itr != prev + 1) {
            beg_itr = itr;
            if (debug) cout << "it Œ©‚Â‚¯‚½ : " << *itr << endl;
            break;
        }
        prev = *itr;
    }

    if (beg_itr == st.end()) {
        cout << "0" << endl;
        return 0;
    }

    auto itr      = beg_itr;
    auto prev_itr = itr;
    while (true) {
        if (debug) cout << "!itr:" << *itr << "  --  ";
        rep(i, hash[*itr].size()) {
            current_sum += hash[*itr][i];
        }

        prev_itr = itr;
        ++itr;
        if (itr == st.end()) itr = st.begin();
        if (itr == beg_itr) break;

        if (*itr != *prev_itr + 1) {
            if (itr == st.begin() && *itr == 0 && *prev_itr == m - 1) continue;
            ans = min(ans, sum_arr - current_sum);
            if (debug) cout << "beg_itr:" << *beg_itr << " itr:" << *itr << " prev:" << *prev_itr << " current_sum:" << current_sum << endl;
            current_sum = 0;
        }
        if (debug) cout << endl;
    }
    ans = min(ans, sum_arr - current_sum);
    cout << ans << endl;

    return 0;
}
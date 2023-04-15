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

int ctoi(char c) {
    return c - '0';
}

int main() {
    bool   debug = false;
    string str;
    cin >> str;

    if (str[0] == '1') {
        cout << "No" << endl;
        return 0;
    }

    vi rows(7, 0);
    rows[0] = ctoi(str[6]);
    rows[1] = ctoi(str[3]);
    rows[2] = ctoi(str[1]) + ctoi(str[7]);
    rows[3] = ctoi(str[0]) + ctoi(str[4]);
    rows[4] = ctoi(str[2]) + ctoi(str[8]);
    rows[5] = ctoi(str[5]);
    rows[6] = ctoi(str[9]);

    if (debug) {
        rep(i, 7) cout << rows[i] << " ";
        cout << endl;
    }

    int left  = 999;
    int right = -999;
    rep(i, 7) {
        if (rows[i] == 0) continue;
        left  = min(left, i);
        right = max(right, i);
    }

    for (int i = left; i <= right; ++i) {
        if (rows[i] == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
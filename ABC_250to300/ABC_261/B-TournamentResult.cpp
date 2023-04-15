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
typedef vector<string>                 vs;

int main() {
    ll n;
    cin >> n;

    vs table(n);
    rep(i, n) cin >> table[i];

    rep(i, n) {
        rep(j, n) {
            // cout << "i:" << i << " j:" << j << endl;
            if (i == j) continue;
            bool flag = true;
            if (table[i][j] == 'D' && table[j][i] != 'D') flag = false;
            if (table[i][j] != 'D' && table[j][i] != 'D' && table[i][j] == table[j][i]) flag = false;
            if (flag == false) {
                cout << "incorrect" << endl;
                return 0;
            }
        }
    }
    cout << "correct" << endl;

    return 0;
}
#include <algorithm>
#include <atcoder/all>
#include <climits>
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
#include <unordered_set>
#include <vector>
using namespace std;
using namespace atcoder;

typedef long long int                  ll;
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<float, float>             pff;
typedef pair<double, double>           pdd;
typedef vector<bool>                   vb;
typedef vector<vector<bool>>           vvb;
typedef vector<vector<vector<bool>>>   vvvb;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<float>                  vf;
typedef vector<vector<float>>          vvf;
typedef vector<vector<vector<float>>>  vvvf;
typedef vector<double>                 vd;
typedef vector<vector<double>>         vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef vector<pii>                    vpii;
typedef vector<vector<pii>>            vvpii;
typedef vector<vector<vector<pii>>>    vvvpii;
typedef vector<pll>                    vpll;
typedef vector<vector<pll>>            vvpll;
typedef vector<vector<vector<pll>>>    vvvpll;
typedef unordered_map<char, char>      umcc;
typedef unordered_map<char, int>       umci;
typedef unordered_map<char, ll>        umcll;
typedef unordered_map<char, string>    umcs;
typedef unordered_map<int, char>       umic;
typedef unordered_map<int, int>        umii;
typedef unordered_map<int, ll>         umill;
typedef unordered_map<int, string>     umis;
typedef unordered_map<ll, ll>          umllll;
typedef unordered_map<ll, string>      umlls;
typedef unordered_map<string, char>    umsc;
typedef unordered_map<string, int>     umsi;
typedef unordered_map<string, ll>      umsll;
typedef unordered_set<char>            usc;
typedef unordered_set<int>             usi;
typedef unordered_set<ll>              usll;
typedef unordered_set<string>          uss;

const double PI = 3.141592653589793;
#define rep(i, n)       for (int i = 0; i < (int)(n); ++i)
#define repe(i, n)      for (int i = 0; i <= (int)(n); ++i)
#define rep1(i, n)      for (int i = 1; i < (int)(n); ++i)
#define rep1e(i, n)     for (int i = 1; i <= (int)(n); ++i)
#define repab(i, a, b)  for (int i = (a); i < (b); ++i)
#define repabe(i, a, b) for (int i = (a); i <= (b); ++i)
#define mod107(m)       m % 1000000007
#define mod998(m)       m % 998244353
const ll m107 = 1000000007;
const ll m998 = 998244353;

// 数値を16桁で表示(誤差が厳しい問題に対応)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush処理は重たい)
#define elnf "\n"

// 競プロ用環境セッティング
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

template <class T>
void printvec(const vector<T> &vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
} // end of func

template <class T>
void printvvec(const vector<T> &vec) {
    rep(i, vec.size()) {
        rep(j, vec[i].size()) cout << vec[i][j] << " ";
        cout << endl;
    }
} // end of func

const bool debug = true;

int main() {
    preprocess();

    int n;
    cin >> n;

    ll inf = LLONG_MAX / 10000;

    vvll prr(n, vll(n)), rrr(n, vll(n)), drr(n, vll(n));
    rep(i, n) {
        rep(j, n) {
            cin >> prr[i][j];
        }
    }
    rep(i, n) {
        rep(j, n - 1) {
            cin >> rrr[i][j];
        }
    }
    rep(i, n - 1) {
        rep(j, n) {
            cin >> drr[i][j];
        }
    }
    // rep(i, n) rrr[i][n - 1] = inf;
    // rep(j, n) drr[n - 1][j] = inf;

    // 各点からゴールまでの距離
    vvll saiteki(n, vll(n, inf));
    saiteki[n - 1][n - 1] = 0;
    // rep(i, n) {
    //     rep(j, n) {
    //         if (i == n - 1 && j == n - 1) continue;
    //         // 右端でない
    //         if (j < n - 1) {
    //             saiteki[i][j + 1] = min(saiteki[i][j + 1], saiteki[i][j] + rrr[i][j]);
    //         }
    //         // 下段でない
    //         if (i < n - 1) {
    //             saiteki[i + 1][j] = min(saiteki[i + 1][j], saiteki[i][j] + drr[i][j]);
    //         }
    //     }
    // }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == 0 && j == 0) continue;
            // 左端でない
            if (0 < j) {
                saiteki[i][j - 1] = min(saiteki[i][j - 1], saiteki[i][j] + rrr[i][j - 1]);
            }
            // 下段でない
            if (0 < i) {
                saiteki[i - 1][j] = min(saiteki[i - 1][j], saiteki[i][j] + drr[i - 1][j]);
            }
        }
    }

    // printvvec(saiteki);

    // vvll charge(n, vll(n, 0));
    // rep(i, n) {
    //     rep(j, n) {
    //         int amari    = saiteki[i][j] % prr[i][j] == 0 ? 0 : 1;
    //         charge[i][j] = saiteki[i][j] / prr[i][j] + amari;
    //     }
    // }

    vvll dp(n, vll(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            // if (i == 0 && j == 0) continue;
            if (i == n - 1 && j == n - 1) continue;

            ll sonoba = inf, migi = inf, sita = inf, amari;
            // // その場でゴールまで稼ぐ
            amari  = saiteki[i][j] % prr[i][j] == 0LL ? 0LL : 1LL;
            sonoba = saiteki[i][j] / prr[i][j] + amari;

            // 右に1個動けるまで稼いで移動する
            if (j < n - 1) {
                amari = rrr[i][j] % prr[i][j] == 0LL ? 0LL : 1LL;
                migi  = rrr[i][j] / prr[i][j] + amari + dp[i][j + 1];
            }

            // 下に1個動けるまで稼いで移動する
            if (i < n - 1) {
                amari = drr[i][j] % prr[i][j] == 0LL ? 0LL : 1LL;
                sita  = drr[i][j] % prr[i][j] + amari + dp[i + 1][j];
            }
            dp[i][j] = min(min(sonoba, migi), sita);
        }
    }
    cout << endl;
    printvvec(dp);

    return 0;
} // end of main

#include <algorithm>
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

    int h, w, k;
    cin >> h >> w >> k;

    vvi masu(h, vi(w, 0));
    vvi yokox(h, vi(1, -1));
    vvi tatex(w, vi(1, -1));

    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if (s[j] == 'o') {
                masu[i][j] = 1;
                continue;
            }
            if (s[j] == '.') continue;

            masu[i][j] = -1;
            yokox[i].emplace_back(j);
            tatex[j].emplace_back(i);
        }
    }

    rep(i, h) yokox[i].emplace_back(w);
    rep(j, w) tatex[j].emplace_back(h);

    // printvvec(yokox);
    // cout << endl;
    // printvvec(tatex);

    int ans = INT_MAX;
    // 横について
    rep(i, h) {
        rep(batu, yokox[i].size() - 1) {
            if (yokox[i][batu + 1] - yokox[i][batu] <= k) continue;
            int count = 0;
            int ind   = yokox[i][batu] + 1;
            rep(_, k) {
                if (masu[i][ind] == 0) count += 1;
                ind += 1;
            }

            // printf("i:%d ind:%d ans:%d\n", i, ind, ans);
            ans = min(ans, count);
            // printf("i:%d ind:%d yoko:%d\n", i, ind, yokox[i][batu + 1]);
            while (ind < yokox[i][batu + 1]) {

                if (masu[i][ind - k] == 0) count -= 1;
                if (masu[i][ind] == 0) count += 1;
                ans = min(ans, count);
                ind += 1;
            }
        }
    }

    // printvvec(tatex);
    // 縦について
    rep(j, w) {
        rep(batu, tatex[j].size() - 1) {
            if (tatex[j][batu + 1] - tatex[j][batu] <= k) continue;

            int count = 0;
            int ind   = tatex[j][batu] + 1;
            rep(_, k) {
                if (masu[ind][j] == 0) count += 1;
                ind += 1;
            }

            ans = min(ans, count);
            while (ind < tatex[j][batu + 1]) {
                if (masu[ind - k][j] == 0) count -= 1;
                if (masu[ind][j] == 0) count += 1;
                ans = min(ans, count);
                ind += 1;
            }
        }
    }

    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;

    return 0;
} // end of main

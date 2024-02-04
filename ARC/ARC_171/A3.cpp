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

const bool debug = false;
#define callno      \
    cout << "No\n"; \
    continue;

int main() {
    preprocess();
    int t;
    cin >> t;

    rep(_, t) {
        if (debug) cout << endl;

        ll n, a, b;
        cin >> n >> a >> b;
        if (n < a || n == a && b > 0) {
            cout << "No\n";
            continue;
        }

        if (a == 0) {
            if (n * n >= b)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }

        if (a == 1) {
            ll ans = 1;
            ans += n - 2;
            ans += n - 2;
            ll height   = n - 2;
            height      = (height + 1) / 2;
            ll migisita = height * (n - 2);

            ans += migisita;
            if (ans >= b)
                cout << "Yes\n";
            else
                cout << "No\n";

            if (debug) printf("ans:%lld %lld\n", ans, migisita);
            continue;
        }

        n -= 1;
        a -= 1;

        // ルークをとにかく入れる
        ll grida    = min(n - a + 1, a);
        ll gridsize = max(0LL, grida * 2 - 1);

        // 外側を消す
        n -= (a - grida);

        // 左上
        ll hidariue = (grida - 1) * (grida - 1);

        // 右上
        ll height = grida - 1;
        ll width  = n - gridsize;
        ll migiue = height * width;

        ll hidarisita = migiue;

        // 右下
        height      = n - gridsize;
        height      = (height + 1) / 2;
        width       = n - gridsize;
        ll migisita = height * width;

        if (debug) printf("--- %lld %lld %lld --- %lld %lld %lld %lld\n", n, grida, gridsize, hidariue, migiue, hidarisita, migisita);

        ll ans = hidariue + migiue + hidarisita + migisita;
        if (ans >= b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
} // end of main

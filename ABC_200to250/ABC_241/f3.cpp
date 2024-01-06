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

struct Unchi {
  public:
    ll x, y, d;
    Unchi() {}
    Unchi(ll yy, ll xx, ll dd) : y(yy), x(xx), d(dd) {}
};

int main() {
    preprocess();

    ll h, w, n;
    cin >> h >> w >> n;
    ll sx, sy, gx, gy;
    cin >> sy >> sx;
    cin >> gy >> gx;

    unordered_map<ll, set<ll>> xs, ys;
    rep(i, n) {
        ll x, y;
        cin >> y >> x;
        ys[y].insert(x);
        xs[x].insert(y);
    }

    queue<Unchi> que;
    que.push(Unchi(sy, sx, 0));
    set<pll> visit;
    while (!que.empty()) {
        auto data = que.front();
        que.pop();
        ll x = data.x;
        ll y = data.y;
        ll d = data.d;

        if (debug) printf("\nx:%lld y:%lld d:%lld\n", x, y, d);

        if (visit.count({y, x}) == 1) continue;
        visit.insert({y, x});

        // 上
        if (xs[x].size() > 0) {
            if (debug) {
                cout << "上下に移動するぞー" << endl;
                for (auto hoge : xs[x])
                    cout << hoge << " ";
                cout << endl;
            }

            auto it = xs[x].upper_bound(y);
            if (it != xs[x].end()) {
                if (x == gx && y <= gy && gy <= *it) {
                    cout << d + 1 << endl;
                    return 0;
                }
                que.push(Unchi(*it - 1, x, d + 1));
                if (debug) printf("上に行った dx:%lld dy:%lld dd:%lld\n", x, *it - 1, d + 1);
            }

            // 下
            it = xs[x].lower_bound(y);
            while (it != xs[x].begin() && *it >= y)
                it--;

            cout << "begin? : " << (it == xs[x].begin()) << "  *it:" << *it << " dist:" << distance(xs[x].begin(), it) << endl;
            if (*it + 1 < y) {
                if (x == gx && *it + 1 <= gy && gy <= y) {
                    cout << d + 1 << endl;
                    return 0;
                }
                que.push(Unchi(*it + 1, x, d + 1));
                if (debug) printf("下に行った dx:%lld dy:%lld dd:%lld\n", x, *it + 1, d + 1);
            }
        }

        if (ys[y].size() > 0) {
            if (debug) {
                cout << "左右に移動するぞー" << endl;
                for (auto hoge : ys[y])
                    cout << hoge << " ";
                cout << endl;
            }

            // 右
            auto it = ys[y].upper_bound(x);
            if (it != ys[y].end()) {
                if (y == gy && x <= gx && gx <= *it) {
                    cout << d + 1 << endl;
                    return 0;
                }
                que.push(Unchi(y, *it - 1, d + 1));
                if (debug) printf("右に行った dx:%lld dy:%lld dd:%lld\n", *it - 1, y, d + 1);
            }

            // 左
            it = ys[y].lower_bound(x);
            while (it != ys[y].begin() && *it > x)
                it--;
            if (*it + 1 < x) {
                if (y == gy && *it + 1 <= gx && gx <= x) {
                    cout << d + 1 << endl;
                    return 0;
                }
                que.push(Unchi(y, *it + 1, d + 1));
                // cout << "hoge[y].size() : " << ys[y].size() << endl;
                // for (auto hoge : ys[y])
                //     cout << hoge << " ";
                // cout << endl;
                if (debug) printf("左に行った dx:%lld dy:%lld dd:%lld\n", *it + 1, y, d + 1);
            }
        }
    }

    cout << -1 << endl;
    return 0;
} // end of main

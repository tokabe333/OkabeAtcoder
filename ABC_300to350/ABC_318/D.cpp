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

struct Edge {
    ll w, a, b;
    Edge() {}
    Edge(ll ww, ll aa, ll bb) : w(ww), a(aa), b(bb) {}

    // bool operator<(const Edge &e1, const Edge &e2) {
    //     return e1.w < e2.w;
    // }
    // bool operator>(const Edge &e1, const Edge &e2) {
    //     return e1.w > e2.w;
    // }
    bool operator<(const Edge &e1) const {
        return this->w < e1.w;
    }
    bool operator>(const Edge &e1) const {
        return this->w > e1.w;
    }
    bool operator==(const Edge &e1) const {
        return this->w == e1.w;
    }
};

vvll graph;

ll dfs(ll depth, ll sum, ll node, vi &flag) {
    flag[node] = 0;
    ll m       = 0;
    rep(i, graph.size()) {
        if (flag[i] == 0) continue;
        flag[i] = 0;
        m       = max(m, dfs(depth + 1, sum + graph[node][i], i, flag));
        flag[i] = 1;
    }
    printf("depth:%lld sum:%lld node:%lld m:%lld\n", depth, sum, node, m);
    return max(m, sum);
}

int main() {
    preprocess();

    int n;
    cin >> n;
    rep(i, n) graph.emplace_back(vll(n));

    rep(i, n - 1) {
        rep(j, n - i - 1) {
            ll hoge;
            cin >> hoge;
            graph[i][i + j + 1] = hoge;
            graph[i + j + 1][i] = hoge;
        }
    }

    vll dp(1 << n, 0);

    rep(b, (1 << n) - 1) {
        rep(i, n - 1) {
            // int l = -1;
            // rep(i, n) {
            //     if ((b >> i & 1) == 0) {
            //         l = i;
            //         break;
            //     }
            // }
            // rep(i, n) {
            //     if ((b >> i & 1) == 0) {
            //         ll hoge  = b | (1 << l) | (1 << i);
            //         dp[hoge] = max(dp[hoge], dp[b] + graph[l][i]);
            //     }
            // }
            rep(i, n - 1) {
                for (int j = i + 1; j < n; ++j) {
                    if (b >> i & 1 || b >> j & 1) continue;
                    int nb = b | (1 << i) | (1 << j);
                    dp[nb] = max(dp[nb], dp[b] + graph[i][j]);
                }
            }
        }
    }
    // rep(i, dp.size()) {
    //     printf("i:%3d ", i);
    //     int    ii = i;
    //     string s  = "";
    //     while (ii > 0) {
    //         s += to_string(ii & 1);
    //         ii >>= 1;
    //     }
    //     reverse(s.begin(), s.end());
    //     cout << s << "  vale:" << dp[i] << endl;
    // }
    cout << dp.back() << endl;
}

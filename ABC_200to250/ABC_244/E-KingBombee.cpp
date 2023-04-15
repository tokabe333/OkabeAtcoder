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
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
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
#define m107            1000000007
#define m998            998244353

// 数値を16桁で表示(誤差が厳しい問題に対応)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush処理は重たい)
#define elnf "\n"

// 競プロ用環境セッティング
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

bool debug = true;

int main() {
    preprocess();
    ll n, m, k, s, t, x, u, v;
    cin >> n >> m >> k >> s >> t >> x;
    s -= 1;
    t -= 1;
    x -= 1;

    vvll graph(n, vll(0));
    rep(i, m) {
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    // 移動距離，ノード番号，偶奇 → パターン数
    vvvll dp(k + 1, vvll(n, vll(2, 0)));
    dp[0][s][0] = 1;

    rep1e(i, k) {
        rep(j, n) {

            // j == x ではない
            if (j != x) {
                for (ll g : graph[j]) {
                    dp[i][j][0] = mod998(dp[i][j][0] + dp[i - 1][g][0]);
                    dp[i][j][1] = mod998(dp[i][j][1] + dp[i - 1][g][1]);
                }
            }
            // j == x なら交差
            else {
                for (ll g : graph[j]) {
                    dp[i][j][0] = mod998(dp[i][j][0] + dp[i - 1][g][1]);
                    dp[i][j][1] = mod998(dp[i][j][1] + dp[i - 1][g][0]);
                }
            }
        }
    }

    cout << mod998(dp[k][t][0]) << endl;

    return 0;
} // end of main

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

vvi graph(200100, vi(2, -1)); // グラフ番号 白黒

// 黒のノード数 白のノード数 グラフの要素数 黒のエッジ数 白のエッジ数
bool dfs(int graph_no, int node, int color, vi &ans) {
    ans[2] += 1;
    ans[color] += 1;

    graph[node][0] = graph_no;
    graph[node][1] = color;

    bool flag = true;
    for (int i = 2; i < graph[node].size(); ++i) {
        ans[color + 3] += 1;
        int next = graph[node][i];

        // 同じ色があると問題
        if (graph[next][1] == color) {
            cout << 0 << endl;
            exit(0);
        }
        if (graph[next][1] == !color) continue;
        flag = flag && dfs(graph_no, next, !color, ans);
    }
    return flag;
}

int main() {
    preprocess();
    ll n, m, u, v;
    cin >> n >> m;

    rep(i, m) {
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vvi answers;
    rep(i, n) {
        if (graph[i][0] != -1) continue;
        vi   ans1(5, 0);
        bool isbip = dfs(i, i, 0, ans1);
        if (isbip) answers.emplace_back(ans1);
    }

    ll ans = n * (n - 1) / 2 - m;
    rep(i, answers.size()) {
        ll bnum = answers[i][0];
        ll wnum = answers[i][1];
        ans -= bnum * (bnum - 1) / 2;
        ans -= wnum * (wnum - 1) / 2;
    }

    if (debug) cout
                   << "bip:" << n << " answers.length:" << answers.size() << endl;
    cout << ans << endl;

    if (debug) {
        cout << endl;
        rep(i, answers.size()) {
            for (auto hoge : answers[i])
                cout << hoge << " ";
            cout << endl;
        }
        cout << endl;

        // rep(i, n) {
        //     for (int hoge : graph[i])
        //         cout << hoge << " ";
        //     cout << endl;
        // }
    }

    return 0;
} // end of main

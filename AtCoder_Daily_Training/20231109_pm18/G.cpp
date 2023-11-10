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
void printvec(vector<T> vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
} // end of func

template <class T>
void printvvec(vector<T> vec) {
    rep(i, vec.size()) {
        rep(j, vec[i].size()) cout << vec[i][j] << " ";
        cout << endl;
    }
} // end of func

const bool debug = false;

bool dfs(const vvi &graph, vi &flag, int node, int color) {
    flag[node] = color;
    bool ret   = true;
    rep(i, graph[node].size()) {
        if (flag[graph[node][i]] == color) return false;
        if (flag[graph[node][i]] != 0) continue;
        ret = ret & dfs(graph, flag, graph[node][i], color * (-1));
    }
    return ret;
}

int count_dfs(const vvi &graph, set<int> &route, int node) {
    route.insert(node);
    int m = graph[node].size();
    rep(i, graph[node].size()) {
        if (route.count(graph[node][i]) == 1) continue;
        m += count_dfs(graph, route, graph[node][i]);
    }
    return m;
}

int main() {
    preprocess();
    int n, m;
    cin >> n >> m;

    vvi graph(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    set<int> ok_graph;
    vi       flag(n, 0);

    int color = 1;
    rep(i, n) {
        if (flag[i] != 0) continue;
        bool ret = dfs(graph, flag, i, color);
        if (ret == true) ok_graph.insert(color);
        color += 1;
    }

    if (debug) {
        printvec(flag);
        for (auto itr = ok_graph.begin(); itr != ok_graph.end(); ++itr)
            cout << *itr << " ";
        cout << endl;
    }

    vvi      katamari;
    set<int> ok_flag;
    rep(i, n) {
        if (ok_graph.count(abs(flag[i])) == 0) continue;
        if (ok_flag.count(abs(flag[i])) == 1) continue;
        ok_flag.insert(abs(flag[i]));
        set<int> route;
        int      m    = count_dfs(graph, route, i);
        vi       hoge = {route.size(), m / 2};
        katamari.push_back(hoge);
    }

    if (debug) printvvec(katamari);

    int ans = 0;
    rep(i, katamari.size()) {
        int black = katamari[i][0] / 2;
        int white = (katamari[i][0] + 1) / 2;
        ans += black * white - katamari[i][1];
        for (int j = i + 1; j < katamari.size(); ++j) {
            ans += katamari[i].size() * katamari[j].size();
        }
    }
    cout << ans << endl;

    return 0;
} // end of main

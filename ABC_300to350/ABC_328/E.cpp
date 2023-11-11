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

const bool debug = true;

typedef pair<int, ll>       pil;
typedef vector<vector<pil>> vvpil;

int n, m;
ll  k;
ll  ans = LLONG_MAX;

bool dfs(const vvpil &graph, set<int> &route, int node, ll cost) {
    // route.insert(node);
    // if (route.size() == n) {
    //     ans = min(ans, cost);
    //     route.erase(node);
    //     return true;
    // }
    // printf("node:%d route.size:%d\n", node, route.size());

    int  n    = graph[node].size();
    bool flag = false;
    rep(i, n) {
        if (route.count(graph[node][i].first) == 0) flag = true;
    }
    if (flag == false) return true;

    // ビット全探索
    for (int bit = 0; bit < (1 << n); ++bit) {
        ll wcost = cost;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                if (route.count(graph[node][i].first) == 0) {
                    route.insert(graph[node][i].first);
                    wcost = (wcost + graph[node][i].second) % k;
                }
            }
        }

        if (route.size() == n) {
            ans = min(ans, wcost);
        }

        rep(i, n) {
            int next = graph[node][i].first;
            if (route.count(next) == 0) continue;
            dfs(graph, route, next, wcost);
        }

        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                route.erase(graph[node][i].first);
            }
        }
    }

    return true;
}

int main() {
    preprocess();

    cin >> n >> m >> k;

    vvpil graph(n);
    rep(i, m) {
        int u, v;
        ll  w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        graph[u].emplace_back(pil(v, w));
        graph[v].emplace_back(pil(u, w));
    }

    // rep(i, n) {
    //     set<int> route;
    //     route.insert(i);
    //     dfs(graph, route, i, 0);
    // }
    set<int> route;
    route.insert(0);
    dfs(graph, route, 0, 0);

    cout << ans << endl;

    return 0;
} // end of main

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
constexpr ll m107 = 1000000007;
constexpr ll m998 = 998244353;

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

typedef ll bf_type;
struct Edge {
    int     from;
    int     to;
    bf_type cost;
    Edge() {}
    Edge(int f, int t, bf_type c) : from(f), to(t), cost(c) {}
};

bool Bellman_Ford(vector<bf_type> &dist, const vector<Edge> &edges, int start_node) {

    // start_nodeからの距離をinfで初期化

    bf_type inf                 = sizeof(bf_type) == 4 ? INT_MAX : LLONG_MAX;
    rep(i, dist.size()) dist[i] = inf;
    dist[start_node]            = 0;

    // 各頂点は高々1回しか通らない
    int          n = dist.size();
    int          m = edges.size();
    vector<bool> posi(n, true);
    rep(i, n) {
        rep(j, m) {
            int     from = edges[j].from;
            int     to   = edges[j].to;
            bf_type cost = edges[j].cost;

            if (dist[from] == inf) continue;
            if (dist[to] <= dist[from] + cost) continue;
            dist[to] = dist[from] + cost;
            if (i >= n - 1) posi[from] = false;
        }
    }

    rep(i, n) {
        rep(j, m) {
            int from = edges[j].from;
            int to   = edges[j].to;
            if (posi[from] == false) posi[to] = false;
        }
    }
    return posi[n - 1];
}

int main() {
    preprocess();
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    rep(i, m) {
        int     a, b;
        bf_type c;
        cin >> a >> b >> c;
        edges[i].from = a - 1;
        edges[i].to   = b - 1;
        edges[i].cost = c * (-1);
    }

    // rep(i, m) {
    //     printf("from:%d to:%d cost:%lld\n", edges[i].from, edges[i].to, edges[i].cost);
    // }

    vll  dist(n);
    bool ret = Bellman_Ford(dist, edges, 0);
    // printvec(dist);
    if (ret == false)
        cout << "inf" << endl;
    else
        cout << dist[n - 1] * (-1) << endl;

    return 0;
} // end of main

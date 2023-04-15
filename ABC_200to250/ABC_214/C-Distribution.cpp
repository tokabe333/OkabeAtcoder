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

bool debug = false;

// 問題に合わせてバイト数を変更
typedef long long            dijint;
typedef pair<dijint, dijint> pdd;
typedef vector<dijint>       vdi;
typedef vector<pdd>          vpdd;
typedef vector<vector<pdd>>  vvpdd;

/// @brief ダイクストラ法である始点から全てのノードまでの距離を探索
/// @param graph
/// @param start
/// @return 距離を列挙した配列
vdi dijkstra(const vvpdd &graph, int start) {
    // 変数用意
    int n = graph.size();

    // とりあえず最大値
    dijint MAX = sizeof(dijint) == 4 ? INT_MAX : LONG_MAX;

    // 距離候補を保持する優先度付きキュー
    priority_queue<pdd, vpdd, greater<pdd>> pque;

    // 確定した距離を保持するreturn用変数
    vdi distance(n, MAX);
    distance[start] = 0;
    pque.push(pdd(0, start));
    while (pque.size() > 0) {
        dijint d = pque.top().first;  // start から u までの距離
        dijint u = pque.top().second; // 距離を知りたいノード
        pque.pop();

        // 既に確定した距離以上なら更新余地がない
        if (distance[u] < d) continue;

        // 各種距離を追加
        for (pdd next : graph[u]) {
            dijint cost      = next.first;
            dijint next_node = next.second;
            // 更新余地がない場合は次
            if (distance[next_node] <= d + cost) continue;
            distance[next_node] = d + cost;
            pque.push(pdd(d + cost, next_node));
        } // end of for
    }     // end of while

    return distance;
} // end of func

int main() {
    preprocess();
    int n;
    cin >> n;
    vi srr(n), trr(n);
    rep(i, n) cin >> srr[i];
    rep(i, n) cin >> trr[i];

    vvpdd graph(n + 1);

    // 高橋くん = n としてグラフ作成
    rep(i, n) {
        graph[n].emplace_back(pdd(trr[i], i));
        graph[i].emplace_back(pdd(trr[i], n));
    }
    rep(i, n) {
        int next = (i + 1) % n;
        graph[i].emplace_back(pdd(srr[i], next));
        // graph[next].emplace_back(pdd(srr[i], i));
    }

    if (debug) {
        rep(i, n + 1) {
            for (pdd hoge : graph[i])
                cout << hoge.first << "_" << hoge.second << " ";
            cout << endl;
        }
    }

    vdi ans = dijkstra(graph, n);
    rep(i, n) cout << ans[i] << elnf;

    return 0;
} // end of main

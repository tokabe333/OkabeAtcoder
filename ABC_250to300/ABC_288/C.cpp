#include <algorithm>
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
#include <vector>

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
#define m107      1000000007
#define m998      998244353
#define Y         first
#define X         second
typedef long long int                  ll;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
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
typedef unordered_map<int, int>        umii;
typedef unordered_map<ll, ll>          umll;
typedef unordered_map<int, string>     umis;
typedef unordered_map<string, int>     umsi;
typedef unordered_map<ll, string>      umls;
typedef unordered_map<string, ll>      umsl;

void dfs(const vvi &graph, set<int> &route, int node, int &route_num, int &node_num) {

    route.insert(node);
    node_num += 1;
    route_num += graph[node].size();

    for (auto next : graph[node]) {
        if (route.count(next) == 1) continue;
        dfs(graph, route, next, route_num, node_num);
    }
}

int main() {
    bool debug = true;
    ll   n, m;
    cin >> n >> m;

    vvi graph(n, vi(0));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    int      ans = 0;
    set<int> route;
    rep(i, n) {
        if (route.count(i) == 1) continue;
        int route_num = 0;
        int node_num  = 0;
        dfs(graph, route, i, route_num, node_num);
        // cout << "node:" << i << " route_num:" << route_num << " node_num:" << node_num << endl;
        ans += max(0, (route_num / 2) - (node_num - 1));
    }

    cout << ans << endl;

    return 0;
}
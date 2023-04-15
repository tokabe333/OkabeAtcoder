#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int              ll;
typedef vector<ll>                 vll;
typedef vector<vector<ll>>         vvll;
typedef vector<vector<vector<ll>>> vvvll;

unordered_map<ll, bool> dic;

stack<ll> dfs(ll index, ll y, stack<ll> &route, const vvll &tree) {
    // cout << "index:" << index << endl;

    route.push(index);
    dic[index] = true;

    if (index == y) {
        string str = "";
        while (route.empty() == false) {
            str += to_string(route.top() + 1);
            route.pop();
        }
        for (int i = str.size() - 1; i >= 0; --i) {
            cout << str[i] << " ";
        }
        cout << endl;
        exit(0);
    }

    rep(i, tree[index].size()) {
        ll hoge = tree[index][i];
        // 同じ道は通らない
        if (dic.find(hoge) != dic.end()) continue;

        dfs(hoge, y, route, tree);
    }

    route.pop();
    return route;
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    x -= 1;
    y -= 1;
    // cout << n << x << y << endl;
    vvll tree(n);
    for (int i = 0; i < n - 1; ++i) {
        ll u, v;
        // cout << " scanf ";
        //        scanf("%lld %lld", &u, &v);
        cin >> u >> v;
        u -= 1;
        v -= 1;

        // cout << "i:" << i << endl;

        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    stack<ll> route;
    dfs(x, y, route, tree);

    return 0;
}
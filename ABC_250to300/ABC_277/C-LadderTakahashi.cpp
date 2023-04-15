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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
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
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;

#include <iostream>
#include <vector>
using namespace std;
typedef int hoge;

// Union-Find
struct UnionFind {
    vector<ll> par, rank, siz;

    // 構�?体�?�初期�?
    UnionFind(ll n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    // 根を求め�?
    ll root(ll x) {
        if (par[x] == -1)
            return x; // x が�?�の場合�?� x を返す
        else
            return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致する�?)
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループを併合す�?
    bool unite(ll x, ll y) {
        ll rx = root(x), ry = root(y); // x 側と y 側の根を取得す�?
        if (rx == ry) return false;    // すでに同じグループ�?�とき�?�何もしな�?
        // union by rank
        if (rank[rx] < rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるよ�?にする
        par[ry] = rx;                          // ry �? rx の子とする
        if (rank[rx] == rank[ry]) rank[rx]++;  // rx 側の rank を調整する
        siz[rx] += siz[ry];                    // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求め�?
    ll size(ll x) {
        return siz[root(x)];
    }
};

int main() {
    ll n;
    cin >> n;

    UnionFind             uf(n * 2 + 10);
    unordered_map<ll, ll> hash;
    set<ll>               st;
    vll                   arr(n);
    vll                   brr(n);

    ll a, b;
    ll index = 0;
    rep(i, n) {
        cin >> a >> b;
        // if (hash.find(a) == hash.end()) {
        //     hash[a] = index;
        //     index += 1;
        // }
        // if (hash.find(b) == hash.end()) {
        //     hash[b] = index;
        //     index += 1;
        // }
        st.insert(a);
        st.insert(b);
        arr[i] = a;
        brr[i] = b;
    }

    if (st.count(1) == 0) {
        cout << 1 << endl;
        return 0;
    }
    for (auto it = st.begin(); it != st.end(); ++it) {
        hash[*it] = index;
        index += 1;
    }

    rep(i, n) {
        arr[i] = hash[arr[i]];
        brr[i] = hash[brr[i]];

        uf.unite(arr[i], brr[i]);
    }

    ll ans = 0;
    rep(i, n) {
        if (uf.issame(1, arr[i]) == true) ans = max(ans, arr[i]);
        if (uf.issame(1, brr[i]) == true) ans = max(ans, brr[i]);
    }

    // rep(i, n) {
    //     cout << "A:" << arr[i] << " B:" << brr[i] << endl;
    // }

    // for (auto it = hash.begin(); it != hash.end(); ++it) {
    //     cout << "key:" << it->first << " value:" << it->second << endl;
    // }

    for (auto it = hash.begin(); it != hash.end(); ++it) {
        if (it->second == ans) {
            cout << it->first << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}
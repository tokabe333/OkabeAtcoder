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
typedef pair<ll, ll>                   pii;
typedef pair<ll, string>               pis;
typedef pair<string, ll>               psi;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCk‚Ì‘g‚Ý‡‚í‚¹‚É‘Î‚µ‚Äˆ—‚ðŽÀs‚·‚é
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}
int main() {
    ll n, m;
    cin >> n >> m;
    vvi mat(n, vi(n, 0));
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    int ans = 0;
    foreach_comb(n, 3, [&ans, &mat](int *indexes) {
        int a = indexes[0];
        int b = indexes[1];
        int c = indexes[2];
        // cout << "a:" << a << " b:" << b << " c:" << c << endl;
        if (mat[a][b] == 1 && mat[b][c] == 1 && mat[c][a] == 1) ans += 1;
    });

    cout << ans << endl;

    return 0;
}
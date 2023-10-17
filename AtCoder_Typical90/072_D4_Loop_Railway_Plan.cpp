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

vi dx = {0, 1, 0, -1};
vi dy = {-1, 0, 1, 0};

int h, w;

int dfs(int y, int x, int depth, int gy, int gx, vvi &flag, const vvi &masu) {
    // printf("y:%d x:%d depth:%d gy:%d gx:%d\n", y, x, depth, gy, gx);

    if (y == gy && x == gx && depth > 2) return depth;
    if (flag[y][x] == 1) return 0;
    if (depth != 0) flag[y][x] = 1;

    int ans = -1;

    rep(i, 4) {
        int yy = y + dy[i];
        int xx = x + dx[i];
        if (xx < 0 || w <= xx || yy < 0 || h <= yy) continue;
        if (masu[yy][xx] == 1) continue;
        if (flag[yy][xx] == 1) continue;

        int res = dfs(yy, xx, depth + 1, gy, gx, flag, masu);
        ans     = max(ans, res);
    }
    // printf("return ans:%d y:%d x:%d depth:%d\n", ans, y, x, depth);
    return ans;
}

int main() {
    preprocess();

    cin >> h >> w;
    vvi masu(h, vi(w, 0));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if (s[j] == '#') masu[i][j] = 1;
        }
    }

    // printvvec(masu);

    int ans = -1;
    rep(i, h) {
        rep(j, w) {
            if (masu[i][j] == 1) continue;
            vvi flag(h, vi(w, 0));
            int res = dfs(i, j, 0, i, j, flag, masu);
            ans     = max(ans, res);
        }
    }
    cout << ans << endl;

    return 0;
} // end of main


#include <algorithm>
#include <atcoder/all>
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
using namespace atcoder;

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

typedef vector<vector<vector<vector<int>>>> vvvvi;

vvvvi piece;
int   n;

bool kasaneru(vvi &masu, vvi &piece, int y, int x) {
    int h   = piece.size();
    int w   = piece[0].size();
    int ms  = masu.size();
    int mms = masu[0].size();
    for (int i = y; i < y + h; ++i) {
        if (ms <= i) return false;
        for (int j = x; j < x + w; ++j) {
            if (mms <= j) return false;
            if (masu[i][j] == 1) return false;
        }
    }

    for (int i = y; i < y + h; ++i) {
        for (int j = x; j < x + w; ++j) {
            masu[i][j] = 1;
        }
    }
    return true;
}

bool check(vvi &masu) {
    rep(i, masu.size()) {
        rep(j, masu[i].size()) {
            if (masu[i][j] == 0) return false;
        }
    }
    return true;
}

bool dfs(vvi &masu, int depth) {
    // printvvec(masu);
    // printf("depth:%d\n", depth);
    if (check(masu)) return true;
    if (depth == n) return false;

    vvi  hoge(masu);
    bool ret = dfs(hoge, depth + 1);
    hoge     = masu;
    if (ret) return true;
    int ms  = masu.size();
    int mms = masu[0].size();
    rep(k, 2) {
        int h = piece[depth][k].size();
        if (ms < h) continue;
        for (int i = 0; i <= masu.size() - h; ++i) {
            int w = piece[depth][k][0].size();
            if (mms < w) continue;
            for (int j = 0; j <= masu[i].size() - w; ++j) {
                bool kasa = kasaneru(hoge, piece[depth][k], i, j);
                // printf("kasaneru masu[i].size():%d h:%d w:%d i:%d j:%d\n", masu[i].size() - w, h, w, i, j);
                // printvvec(piece[depth][k]);
                // printf("kasa : %d\n", kasa);
                // cout << endl;
                if (kasa == false) continue;
                ret  = dfs(hoge, depth + 1);
                hoge = masu;
                if (ret == true) return true;
            }
        }
    }
    return false;
}

int main() {
    preprocess();

    int h, w;
    cin >> n >> h >> w;
    // vvvvi piece(n, vvvi(2));
    piece.resize(n);
    rep(i, n) {
        piece[i].resize(2);
        int a, b;
        cin >> a >> b;
        piece[i][0] = vvi(a, vi(b, 1));
        piece[i][1] = vvi(b, vi(a, 1));
    }

    vvi    masu(h, vi(w, 0));
    bool   ret = dfs(masu, 0);
    string ans = ret ? "Yes" : "No";
    cout << ans << endl;

    return 0;
} // end of main

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

vvi rotate90(const vvi &poly) {
    vvi masu(4, vi(4));
    rep(i, 4) {
        rep(j, 4) {
            masu[i][j] = poly[j][3 - i];
        }
    }
    return masu;
}

bool check(const vvi &masu) {
    rep(i, 4) {
        rep(j, 4) {
            if (masu[i][j] == 0) return false;
        }
    }
    return true;
}

bool put(vvi &masu, const vvi &poly, int y, int x) {
    rep(i, 4) {
        rep(j, 4) {
            if (poly[i][j] == 0) continue;
            if (y + i < 0 || 4 <= y + i) return false;
            if (x + j < 0 || 4 <= x + j) return false;
            if (masu[y + i][x + j] == 1) return false;
            masu[y + i][x + j] = 1;
        }
    }
    return true;
}

void dfs(const vvi &masu, const vvvi &poly, int depth) {
    // cout << "depth:" << depth << endl;
    // printvvec(masu);
    // cout << endl;

    if (depth == 3) {
        bool ret = check(masu);
        if (ret == true) {
            cout << "Yes" << endl;
            exit(0);
        } else {
            return;
        }
    }

    vvi pol = poly[depth];
    rep(k, 4) {
        for (int i = -3; i <= 3; ++i) {
            for (int j = -3; j <= 3; ++j) {
                vvi  hoge = masu;
                bool ret  = put(hoge, pol, i, j);
                if (ret == false) continue;
                dfs(hoge, poly, depth + 1);
            }
        }
        pol = rotate90(pol);
    }
}

int main() {
    preprocess();

    vvvi polys(3, vvi(4, vi(4, 0)));
    rep(k, 3) {
        rep(i, 4) {
            rep(j, 4) {
                char c;
                cin >> c;
                if (c == '#') polys[k][i][j] = 1;
            }
        }
    }

    vvi masu(4, vi(4, 0));
    dfs(masu, polys, 0);
    // vvi hoge = rotate90(polys[0]);
    // printvvec(hoge);
    // cout << endl;
    // vvi hoge2 = rotate90(hoge);
    // printvvec(hoge2);
    // cout << endl;
    // vvi hoge3 = rotate90(hoge2);
    // printvvec(hoge3);
    // cout << endl;
    // vvi hoge4 = rotate90(hoge3);
    // printvvec(hoge4);
    cout << "No" << endl;
    return 0;
} // end of main

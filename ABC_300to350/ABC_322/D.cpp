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

const bool debug = false;

vvi rotate90(const vvi &poly) {
    vvi hoge(4, vi(4, 0));
    rep(i, 4) {
        rep(j, 4) {
            hoge[3 - j][i] = poly[i][j];
        }
    }
    return hoge;
}

bool put(const vvi &pol, vvi &masu, int y, int x) {
    rep(i, 4) {
        rep(j, 4) {
            if (pol[i][j] == 0) continue;
            if (y + i < 0 || 3 < y + i) return false;
            if (x + j < 0 || 3 < x + j) return false;
            if (masu[y + i][x + j] == 1) return false;
        }
    }

    rep(i, 4) {
        rep(j, 4) {
            if (pol[i][j] == 0) continue;
            masu[y + i][x + j] = 1;
        }
    }
    return true;
}

bool dfs(const vvvi &poly, const vvi &masu, int depth) {
    if (depth == 3) {
        int s = 0;
        rep(i, 4) {
            rep(j, 4) s += masu[i][j];
        }

        if (debug) {
            cout << "depth:" << depth << " s:" << s << endl;
            printvvec(masu);
        }

        if (s != 16) return false;
        return true;
    }

    for (int i = -3; i <= 3; ++i) {
        for (int j = -3; j <= 3; ++j) {
            vvi  m = masu;
            bool p = put(poly[depth], m, i, j);
            if (p == false) continue;
            bool result = dfs(poly, m, depth + 1);
            if (result == true) return true;
        }
    }
    return false;
}

int main() {
    preprocess();
    vvvi poly(3, vvi(4, vi(4, 0)));
    char c;

    rep(i, 3) {
        rep(j, 4) {
            rep(k, 4) {
                cin >> c;
                if (c == '#') poly[i][j][k] = 1;
            }
        }
    }

    vvi masu(4, vi(4, 0));
    rep(k, 4) {
        poly[2] = rotate90(poly[2]);
        rep(j, 4) {
            poly[1] = rotate90(poly[1]);
            rep(i, 4) {
                poly[0]     = rotate90(poly[0]);
                bool result = dfs(poly, masu, 0);

                if (result == false) continue;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
} // end of main

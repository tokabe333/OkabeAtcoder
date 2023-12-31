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

void recursive_comb(int *indexes, int s, int rest,
                    std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

// nPnの順列に対して処理を実行する
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++)
        indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

// nPkの順列に対して処理を実行する
void foreach_permutation(int n, int k, std::function<void(int *)> f) {
    foreach_comb(n, k, [&](int *c_indexes) {
        foreach_permutation(k, [&](int *p_indexes) {
            int indexes[k];
            for (int i = 0; i < k; i++) {
                indexes[i] = c_indexes[p_indexes[i]];
            }
            f(indexes);
        });
    });
}

const bool debug = false;

vvi brr;

bool check(const vvi &arr, int h, int w) {
    rep(i, h) {
        rep(j, w) {
            if (arr[i][j] != brr[i][j]) return false;
        }
    }
    return true;
}

int main() {
    preprocess();
    int h, w;
    cin >> h >> w;
    int ahw;
    vvi arr;
    rep(i, h) {
        arr.emplace_back(vi());
        rep(j, w) {
            cin >> ahw;
            arr[i].emplace_back(ahw);
        }
    }

    rep(i, h) {
        brr.emplace_back(vi());
        rep(j, w) {
            cin >> ahw;
            brr[i].emplace_back(ahw);
        }
    }

    int ans = INT_MAX;
    foreach_permutation(h, h, [/*h, w, arr, ans*/ &](int *rswap) {
        foreach_permutation(w, w, [/*h, w, rswap, arr, ans*/ &](int *cswap) {
            // for (int i = 0; i < h; ++i) {
            //     cout << indexes[i] << ",";
            // }
            // cout << "  |  ";

            // for (int i = 0; i < w; ++i) {
            //     std::cout << indexes2[i] << ",";
            // }
            // std::cout << std::endl;

            vvi crr(h, vi(w));
            rep(i, h) {
                rep(j, w) {
                    crr[i][j] = arr[rswap[i]][cswap[j]];
                }
            }

            bool ret = check(crr, h, w);
            if (ret == false) return 0;

            if (debug) {
                cout << "\nitti" << endl;
                cout << "rswap : ";
                rep(i, h) cout << rswap[i] << " ";
                cout << "\ncswap : ";
                rep(j, w) cout << cswap[j] << " ";
                cout << endl;

                rep(i, h) {
                    rep(j, w) cout << crr[i][j] << " ";
                    cout << endl;
                }
                cout << endl;
            }

            int count = 0;
            for (int i = 0; i < h - 1; ++i) {
                for (int j = i + 1; j < h; ++j) {
                    if (rswap[i] > rswap[j]) count += 1;
                }
            }
            for (int i = 0; i < w - 1; ++i) {
                for (int j = i + 1; j < w; ++j) {
                    if (cswap[i] > cswap[j]) count += 1;
                }
            }

            ans = min(ans, count);
        });
    });

    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;

    return 0;
} // end of main

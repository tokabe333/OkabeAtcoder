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
#define Y    first
#define X    second

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

int main() {
    preprocess();
    vvi    masu(9, vi(9, 0));
    string s;
    rep(i, 9) {
        cin >> s;
        rep(j, 9) {
            if (s[j] == '#') masu[i][j] = 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 81 - 3; ++i) {
        for (int j = i + 1; j < 81 - 2; ++j) {
            for (int k = j + 1; k < 81 - 1; ++k) {
                for (int l = k + 1; l < 81; ++l) {
                    vvi p(4, vi(2));
                    p[0][0] = i / 9;
                    p[0][1] = i % 9;
                    p[1][0] = j / 9;
                    p[1][1] = j % 9;
                    p[2][0] = k / 9;
                    p[2][1] = k % 9;
                    p[3][0] = l / 9;
                    p[3][1] = l % 9;

                    bool flag = true;
                    rep(i, 4) {
                        if (masu[p[i][0]][p[i][1]] == 0) flag = false;
                    }
                    if (flag == false) continue;

                    vi dist;
                    rep(m, 3) {
                        for (int n = m + 1; n < 4; ++n) {
                            int y = p[m][0] - p[n][0];
                            int x = p[m][1] - p[n][1];
                            dist.emplace_back(y * y + x * x);
                        }
                    }

                    sort(dist.begin(), dist.end());
                    if (dist[0] == dist[1] && dist[0] == dist[2] && dist[0] == dist[3] && dist[0] * 2 == dist[4] && dist[0] * 2 == dist[5]) {
                        // printvec(dist);
                        // printf("i:%d j:%d k:%d l:%d\n", i, j, k, l);
                        ans += 1;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
} // end of main

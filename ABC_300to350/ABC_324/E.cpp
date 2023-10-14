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

int main() {
    preprocess();
    int n;
    cin >> n;
    string t;
    cin >> t;
    vs srr(n);
    rep(i, n) cin >> srr[i];

    vi head(n, 0), tail(n, 0);

    rep(i, n) {
        string s  = srr[i];
        int    ti = 0;
        rep(j, s.size()) {
            if (s[j] != t[ti]) continue;
            head[i] += 1;
            ti += 1;
            if (ti == t.size()) break;
        }
    }

    rep(i, n) {
        string s  = srr[i];
        int    ti = t.size() - 1;
        for (int j = s.size() - 1; j >= 0; --j) {
            if (s[j] != t[ti]) continue;
            tail[i] += 1;
            ti -= 1;
            if (ti == -1) break;
        }
    }

    vi tlens(n + 1, 0);
    rep(i, n) {
        tlens[tail[i]] += 1;
    }

    vi conc(n + 1, 0);
    conc[n] = tlens[n];
    for (int i = n - 1; i >= 0; --i) {
        conc[i] = tlens[i] + conc[i + 1];
    }

    int ans = 0;
    rep(i, n) {
        ans += conc[t.size() - head[i]];
    }

    cout << ans << endl;

    // rep(i, n) {
    //     printf("i:%d num:%d\n", i, head[i]);
    // }
    // cout << endl;
    // rep(i, n) {
    //     printf("i:%d num:%d\n", i, tail[i]);
    // }
    // cout << endl;
    // rep(i, n + 1) {
    //     printf("i:%d num:%d\n", i, tlens[i]);
    // }
    // cout << endl;
    // rep(i, n + 1) {
    //     printf("i:%d num:%d\n", i, conc[i]);
    // }

    return 0;
} // end of main

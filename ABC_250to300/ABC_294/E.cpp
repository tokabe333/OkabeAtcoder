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
#define m107            1000000007
#define m998            998244353

// 数値を16桁で表示(誤差が厳しい問題に対応)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush処理は重たい)
#define elnf "\n"

// 競プロ用環境セッティング
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

bool debug = false;

int main() {
    preprocess();
    ll L, n1, n2;
    cin >> L >> n1 >> n2;

    vector<pll> arr(n1), brr(n2);
    ll          v, l;
    rep(i, n1) {
        cin >> v >> l;
        arr[i] = pll(v, l);
    }
    rep(i, n2) {
        cin >> v >> l;
        brr[i] = pll(v, l);
    }

    ll  uind = 0, dind = 0;
    pll urange(0, arr[0].second);
    pll drange(0, brr[0].second);
    ll  uvalue = arr[0].first, dvalue = brr[0].first;
    ll  ans = 0;
    while (uind < n1 && dind < n2) {
        if (debug) cout << "urange(" << urange.first << "," << urange.second << ") drange(" << drange.first << "," << drange.second << ") values(" << uvalue << "," << dvalue << ")  ans:" << ans << endl;
        int nextrow = 1;
        if (urange.second < drange.first) {
            nextrow = 1;
        } else if (drange.second < urange.first) {
            nextrow = 2;
        } else if (urange.first < drange.first && drange.second < urange.second) {
            if (uvalue == dvalue) ans += drange.second - drange.first;
            nextrow = 2;
        } else if (drange.first < urange.first && urange.second < drange.second) {
            if (uvalue == dvalue) ans += urange.second - urange.first;
            nextrow = 1;
        } else if (urange.second < drange.second) {
            if (uvalue == dvalue) ans += urange.second - max(urange.first, drange.first);
            nextrow = 1;
        } else if (drange.second < urange.second) {
            if (uvalue == dvalue) ans += drange.second - max(urange.first, drange.first);
            nextrow = 2;
        } else if (urange.first == drange.first && urange.second == drange.second) {
            if (uvalue == dvalue) ans += drange.second - drange.first;
            nextrow = 3;
        }

        if (nextrow % 2 == 1 && uind < n1 - 1) {
            uind += 1;
            urange = pll(urange.second, urange.second + arr[uind].second);
            uvalue = arr[uind].first;
        } else if (nextrow / 2 == 1 && dind < n2 - 1) {
            dind += 1;
            drange = pll(drange.second, drange.second + brr[dind].second);
            dvalue = brr[dind].first;
        } else {
            break;
        }
    }

    if (uvalue == dvalue && urange.first != drange.first) {
        ans += L - max(urange.first, drange.first);
    }

    if (debug) cout << "urange(" << urange.first << "," << urange.second << ") drange(" << drange.first << "," << drange.second << ") values(" << uvalue << "," << dvalue << ")  ans:" << ans << endl;
    cout << ans << endl;

    return 0;
} // end of main

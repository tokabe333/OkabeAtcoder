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

double calc(double c, const vd &arr) {
    double num = 0;
    rep(i, arr.size()) num += abs(c - arr[i]);
    return num;
}

double mind(double a, double b) {
    if (a < b)
        return a;
    else
        return b;
}

int main() {
    preprocess();
    ll n;
    cin >> n;
    vd xrr(n), yrr(n);
    rep(i, n) {
        cin >> xrr[i] >> yrr[i];
    }

    // 三分探索？ 水平
    int    count = 1000;
    double lowx  = pow(10, 9) * (-1) - 1;
    double highx = pow(10, 9) + 1;
    while (count > 0) {
        double c1 = (lowx * 2 + highx) / 3;
        double c2 = (lowx + highx * 2) / 3;

        double fc1 = calc(c1, xrr);
        double fc2 = calc(c2, xrr);
        if (fc1 > fc2)
            lowx = c1;
        else
            highx = c2;

        count -= 1;
    }

    count        = 1000;
    double lowy  = pow(10, 9) * (-1) - 1;
    double highy = pow(10, 9) + 1;
    while (count > 0) {
        double c1 = (lowy * 2 + highy) / 3;
        double c2 = (lowy + highy * 2) / 3;

        double fc1 = calc(c1, yrr);
        double fc2 = calc(c2, yrr);
        if (fc1 > fc2)
            lowy = c1;
        else
            highy = c2;

        count -= 1;
    }

    double ansx = calc(lowx, xrr);
    ansx        = mind(ansx, calc(round(lowx), xrr));
    ansx        = mind(ansx, calc(floor(lowx), xrr));
    ansx        = mind(ansx, calc(ceil(lowx), xrr));

    double ansy = calc(lowy, yrr);
    ansy        = mind(ansy, calc(round(lowx), yrr));
    ansy        = mind(ansy, calc(floor(lowx), yrr));
    ansy        = mind(ansy, calc(ceil(lowx), yrr));

    // printf("lowx:%lf highx:%lf calc:%lf\n", lowx, highx, calc(lowx, xrr));
    // printf("lowy:%lf highy:%lf calc:%lf\n", lowy, highy, calc(lowy, yrr));

    cout << (ll)(ansx + ansy) << endl;

    return 0;
} // end of main

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

ll yaju = 114514810;

struct Cube {
  public:
    ll x1;
    ll x2;
    ll y1;
    ll y2;
    ll z1;
    ll z2;
    Cube(ll x1, ll x2, ll y1, ll y2, ll z1, ll z2) : x1(x1), x2(x2), y1(y1), y2(y2), z1(z1), z2(z2){};
};

ll CalcV(Cube c) {
    return (c.x2 - c.x1) * (c.y2 - c.y1) * (c.z2 - c.z1);
}

Cube kasanari2(Cube a, Cube b) {
    Cube c = {0, 0, 0, 0, 0, 0};

    if (a.x1 > b.x1 || (a.x1 == b.x1 && a.x2 > b.x2)) {
        ll tmp = a.x1;
        a.x1   = b.x1;
        b.x1   = tmp;

        tmp  = a.x2;
        a.x2 = b.x2;
        b.x2 = tmp;
    }

    // 離れている
    if (a.x2 <= b.x1) {
        c.x1 = yaju;
        c.x2 = yaju;
    }
    // 内包している
    else if (a.x1 <= b.x1 && b.x2 <= a.x2) {
        c.x1 = b.x1;
        c.x2 = b.x2;
    }
    // ズレている
    else {
        c.x1 = b.x1;
        c.x2 = a.x2;
    }

    if (a.y1 > b.y1 || (a.y1 == b.y1 && a.y2 > b.y2)) {
        ll tmp = a.y1;
        a.y1   = b.y1;
        b.y1   = tmp;

        tmp  = a.y2;
        a.y2 = b.y2;
        b.y2 = tmp;
    }

    // 離れている
    if (a.y2 <= b.y1) {
        c.y1 = yaju;
        c.y2 = yaju;
    }
    // 内包している
    else if (a.y1 <= b.y1 && b.y2 <= a.y2) {
        c.y1 = b.y1;
        c.y2 = b.y2;
    }
    // ズレている
    else {
        c.y1 = b.y1;
        c.y2 = a.y2;
    }

    if (a.z1 > b.z1 || (a.z1 == b.z1 && a.z2 > b.z2)) {
        ll tmp = a.z1;
        a.z1   = b.z1;
        b.z1   = tmp;

        tmp  = a.z2;
        a.z2 = b.z2;
        b.z2 = tmp;
    }

    // 離れている
    if (a.z2 <= b.z1) {
        c.z1 = yaju;
        c.z2 = yaju;
    }
    // 内包している
    else if (a.z1 <= b.z1 && b.z2 <= a.z2) {
        c.z1 = b.z1;
        c.z2 = b.z2;
    }
    // ズレている
    else {
        c.z1 = b.z1;
        c.z2 = a.z2;
    }

    return c;
}

Cube kasanari3(Cube a, Cube b, Cube c) {
    Cube d = kasanari2(a, b);
    return kasanari2(d, c);
}

void printCube(Cube a) {
    printf("%lld %lld %lld %lld %lld %lld\n", a.x1, a.x2, a.y1, a.y2, a.z1, a.z2);
}

int main() {
    preprocess();

    // Cube aa = {0, 7, 0, 7, 0, 7};
    // Cube bb = {0, 7, 6, 13, 0, 7};
    // Cube cc = {6, 13, 0, 7, 0, 7};

    // ll vvv3 = CalcV(kasanari3(aa, bb, cc));
    // ll vvv2 = CalcV(kasanari2(aa, bb)) + CalcV(kasanari2(bb, cc)) + CalcV(kasanari2(cc, aa)) - (vvv3 * 3);
    // ll vvv1 = CalcV(aa) + CalcV(bb) + CalcV(cc) - (vvv2 * 2) - (vvv3 * 3);

    // cout << vvv1 << endl
    //      << vvv2 << endl
    //      << vvv3 << endl;

    ll vv1, vv2, vv3;
    cin >> vv1 >> vv2 >> vv3;

    Cube a = {0, 7, 0, 7, 0, 7};
    for (ll i = 0; i <= 7; ++i) {
        for (ll j = 0; j <= 7; ++j) {
            for (ll k = 0; k <= 7; ++k) {
                Cube b = {i, i + 7, j, j + 7, k, k + 7};

                for (ll l = -7; l <= 14; ++l) {
                    for (ll m = -7; m <= 14; ++m) {
                        for (ll n = -7; n <= 14; ++n) {
                            Cube c = {l, l + 7, m, m + 7, n, n + 7};

                            ll v3 = CalcV(kasanari3(a, b, c));
                            ll v2 = CalcV(kasanari2(a, b)) + CalcV(kasanari2(b, c)) + CalcV(kasanari2(c, a)) - (v3 * 3);
                            ll v1 = CalcV(a) + CalcV(b) + CalcV(c) - (v2 * 2) - (v3 * 3);
                            if (v1 == vv1 && v2 == vv2 && v3 == vv3) {
                                cout << "Yes" << endl;
                                printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n", a.x1, a.y1, a.z1, b.x1, b.y1, b.z1, c.x1, c.y1, c.z1);
                                return 0;
                            }
                        }
                    }
                }

                //
            }
        }
    }
    cout << "No" << endl;
    return 0;
} // end of main

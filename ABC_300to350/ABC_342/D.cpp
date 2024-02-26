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

// 素因数分解をする a^n のとき pair(a, n);
template <class T>
vector<pair<T, T>> prime_division(T n) {
    vector<pair<T, T>> ret;
    for (T a = 2; a * a <= n; ++a) {
        if (n % a != 0) continue;
        T ex = 0;
        while (n % a == 0) {
            ex += 1;
            n /= a;
        }

        ret.emplace_back(pair<T, T>(a, ex));
    }

    if (n != 1) ret.emplace_back(pair<T, T>(n, 1));
    return ret;
} // end of prime_division;

int main() {
    preprocess();

    int n;
    cin >> n;

    // 2 * 10 ^5 以下の平方数を列挙
    set<ll> heihou;
    ll      hei = 0;
    while (hei * hei <= 2 * pow(10, 5)) {
        heihou.insert(hei * hei);
        hei += 1;
    }

    vll                 arr(n);
    vector<map<ll, ll>> count(2 * pow(10, 5) + 10);
    ll                  zeros   = 0;
    ll                  heihous = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        arr[i] = a;
        if (a == 0) {
            zeros += 1;
            continue;
        }
        if (heihou.count(a) == 1) {
            heihous += 1;
            continue;
        }

        auto primes = prime_division<ll>(a);
        ll   tei    = 0;
        for (pll p : primes) {
            if (p.second % 2 == 0) continue;
            tei = p.first;
        }
        ll value = 1;
        for (pll p : primes) {
            if (p.second % 2 == 1) value *= p.first;
        }

        // printf("a:%lld tei:%lld value:%lld\n", a, tei, value);
        count[tei][value] += 1;
    }

    ll ans = 0;
    while (zeros > 0) {
        ans += n - zeros;
        zeros--;
    }

    // printf("zeros ans:%lld\n", ans);
    ans += heihous * (heihous - 1) / 2;
    // printf("heihous ans:%lld\n", ans);

    rep(i, count.size()) {
        for (pll p : count[i]) {
            ans += p.second * (p.second - 1) / 2;
        }
    }

    cout << ans << endl;

} // end of main

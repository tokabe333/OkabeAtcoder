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

int check(const vector<pii> &arr, int x) {
    int res = 0;
    rep(i, arr.size()) {
        if (arr[i].first < x && arr[i].second == 0 ||
            arr[i].first >= x && arr[i].second == 1) res += 1;
    }
    return res;
}

int main() {
    preprocess();
    int    n;
    string s;
    cin >> n;
    cin >> s;

    vi wrr(n);
    rep(i, n) cin >> wrr[i];

    vector<pair<int, int>> arr(n);
    rep(i, n) {
        int c  = s[i] - '0';
        int w  = c == 0 ? wrr[i] + 0 : wrr[i];
        arr[i] = pair<int, int>(w, c);
    }

    sort(arr.begin(), arr.end());

    vi children(n, 0);
    if (arr[0].second == 0) children[0] = 1;
    rep1(i, n) {
        int hoge    = arr[i].second == 0 ? 1 : 0;
        children[i] = children[i - 1] + hoge;
    }

    vi parent(n, 0);
    if (arr[n - 1].second == 1) parent[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        int hoge  = arr[i].second == 1 ? 1 : 0;
        parent[i] = parent[i + 1] + hoge;
    }

    // rep(i, n) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }
    // printvec(children);
    // printvec(parent);

    int ans  = parent[0];
    int pare = parent.back();
    int i    = 1;
    while (i < n) {
        while (arr[i].first == arr[i - 1].first) {
            ++i;
        }
        int c = children[i];
        int p = parent[i];
        ans   = max(ans, c + p);
        // printf("i:%d c:%d p:%d ans:%d\n", i, c, p, ans);
        ++i;
    }

    ans = max(ans, children.back() + parent.back());
    cout << ans << endl;

    return 0;
} // end of main

#include <algorithm>
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
#include <vector>

typedef int XY_Type;
class XY {
  public:
    XY_Type y;
    XY_Type x;

    XY() {}

    XY(XY_Type y, XY_Type x) {
        this->y = y;
        this->x = x;
    }

    XY operator+(const XY &dst) {
        return XY(this->y + dst.y, this->x + dst.x);
    }

    XY operator-(const XY &dst) {
        return XY(this->y - dst.y, this->x - dst.x);
    }

    XY operator*(const XY_Type &dst) {
        return XY(this->y * dst, this->x * dst);
    }

    XY operator/(const XY_Type &dst) {
        return XY(this->y / dst, this->x / dst);
    }

    double norm() {
        return sqrt(this->y * this->y + this->x * this->x);
    }
};

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
#define m107      1000000007
#define m998      998244353
#define Y         first
#define X         second
typedef long long int                  ll;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
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
typedef unordered_map<int, int>        umii;
typedef unordered_map<ll, ll>          umll;
typedef unordered_map<int, string>     umis;
typedef unordered_map<string, int>     umsi;
typedef unordered_map<ll, string>      umls;
typedef unordered_map<string, ll>      umsl;

bool debug = false;
ll   bin_search(ll a, ll b) {
    double aa = a, bb = b;
    bool   up   = true;
    ll     prev = -9223372036854775807;
    ll     l    = 0;
    ll     r    = 9223372036854775807;

    while (true) {
        ll mid = (l + r) / 2;
        if (mid == 0) return 0;
        double diff = -1;
        if (mid == 1)
            diff = aa / sqrt(2);
        else
            diff = abs(aa / sqrt(mid - 1) - aa / sqrt(mid));

        if (debug) cout << "l:" << l << " mid:" << mid << " r:" << r << " diff:" << diff << endl;

        if (diff == bb) {
            return mid;
        } else if (diff < bb) {
            r = mid;
        } else {
            l = mid;
        }

        if (prev == mid) break;
        prev = mid;
    }

    return prev;
}

ll bin_search2(ll a, ll b, ll g) {
    double aa = a, bb = b, gg = g;
    ll     l    = 0;
    ll     r    = g + 1;
    ll     prev = g + 334;

    double diff;
    while (true) {
        ll mid = (l + r) / 2;
        if (mid == 0)
            return 0;
        else if (mid == 1)
            diff = aa / sqrt(2);
        else
            diff = aa / sqrt(mid) - aa / sqrt(mid - 1);

        if (diff >= 0)
            r = mid;
        else
            l = mid;

        if (prev == mid) break;
        prev = mid;
    }

    return prev;
}

int main() {

    ll a, b;
    cin >> a >> b;

    ll g_num = bin_search(a, b);
    if (debug) cout << "\ngnum:" << g_num << endl;

    ll     ans_g = bin_search2(a, b, g_num);
    double ans;
    if (debug) cout << "ans_g:" << ans_g << endl;
    if (ans_g == 0)
        ans = a;
    else
        ans = a / sqrt(ans_g) + b * (ans_g - 1);

    printf("%.10lf\n", ans);

    return 0;
}
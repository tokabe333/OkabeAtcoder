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

int main() {
    bool debug = true;
    int  n, x;
    cin >> n >> x;

    vvi dp(x + 1, vi(n + 1, 0));
    dp[0][0] = 1;

    vvi ab(n + 1, vi(2, 0));
    rep(i, n) {
        cin >> ab[i + 1][0] >> ab[i + 1][1];
    }

    for (int j = 1; j <= n; ++j) {
        for (int i = 0; i <= x; ++i) {
            if (dp[i][j - 1] == 0) continue;

            for (int k = 0; k <= ab[j][1]; ++k) {
                int h = i + k * ab[j][0];
                if (h > x) break;
                dp[h][j] = 1;
            }
        }
    }

    string str = dp[x][n] == 1 ? "Yes" : "No";
    cout << str << endl;

    return 0;
}
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

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;

bool        debug = true;
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

    XY operator*(const double &dst) {
        return XY(this->y * dst, this->x * dst);
    }

    XY operator/(const double &dst) {
        return XY(this->y / dst, this->x / dst);
    }

    double norm() {
        return sqrt(this->y * this->y + this->x * this->x);
    }
};

double angle_deg(XY a, XY b, XY c) {
    XY v1 = a - b;
    XY v2 = c - b;

    double cos_value = (v1.y * v2.y + v1.x * v2.x) / (v1.norm() * v2.norm());
    return acos(cos_value) * 180 / PI;
}

double gaiseki(const XY &a, const XY &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    vector<XY> arr(4);
    rep(i, 4) {
        int x, y;
        cin >> x >> y;
        arr[i] = XY(y + 1000, x + 1000);
    }

    bool flag = true;
    rep(i, 4) {
        auto p1 = arr[i];
        auto p2 = arr[(i + 1) % 4];
        auto p3 = arr[(i + 2) % 4];
        auto p4 = arr[(i + 3) % 4];

        auto s2 = p2 - p1;
        auto s3 = p3 - p1;
        auto s4 = p4 - p1;

        double g1 = gaiseki(p1, s2);
        double g2 = gaiseki(p1, s3);
        double g3 = gaiseki(p1, s4);
        if (debug) printf("g1:%lf g2:%lf g3:%lf\n", g1, g2, g3);
        if ((g1 < 0 && g2 < 0 && g3 < 0)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
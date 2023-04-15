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
    bool debug = false;
    ll   height, width, n, h, w;
    cin >> height >> width >> n >> h >> w;

    // マスを作って数え上げ
    vvi                     masu(height, vi(width));
    unordered_map<int, int> zentai_kosu;
    int                     hoge;
    rep(i, height) {
        rep(j, width) {
            cin >> hoge;
            masu[i][j] = hoge;

            if (zentai_kosu.find(hoge) != zentai_kosu.end())
                zentai_kosu[hoge] += 1;
            else
                zentai_kosu[hoge] = 1;
        }
    }

    if (debug) {
        for (auto it = zentai_kosu.begin(); it != zentai_kosu.end(); ++it) {
            cout << "key:" << it->first << " value:" << it->second << endl;
        }
    }

    // とりあえず範囲を出す
    unordered_map<int, int> hanni_kosu;
    rep(i, h) {
        rep(j, w) {
            hoge = masu[i][j];
            if (hanni_kosu.find(hoge) != hanni_kosu.end())
                hanni_kosu[hoge] += 1;
            else
                hanni_kosu[hoge] = 1;
        }
    }
    auto backup_hanni_kosu = hanni_kosu;

    // unordered_map<int, int> hanni_kosu2 = hanni_kosu;
    // if (debug) {
    //     for (auto it = hanni_kosu.begin(); it != hanni_kosu.end(); ++it) {
    //         cout << "key:" << it->first << " value:" << it->second << endl;
    //     }
    // }

    // 移動しながら頑張る
    int ans   = 0;
    int key   = 0;
    int value = 0;

    if (debug) cout << "height-h :" << height - h << " width-w :" << width - w << endl;
    for (int i = 0; i <= height - h; ++i) {
        if (i > 0) {
            // バックアップから読み出し
            hanni_kosu = backup_hanni_kosu;

            // 上下に移動する
            rep(j, w) {
                hanni_kosu[masu[i - 1][j]] -= 1;

                hoge = masu[i + h - 1][j];
                if (hanni_kosu.find(hoge) != hanni_kosu.end())
                    hanni_kosu[hoge] += 1;
                else
                    hanni_kosu[hoge] = 1;
            }

            // 保存
            backup_hanni_kosu = hanni_kosu;
        }

        // とりあえず1回
        ans = 0;
        for (auto it = zentai_kosu.begin(); it != zentai_kosu.end(); ++it) {
            key   = it->first;
            value = it->second;
            if (hanni_kosu.find(key) == hanni_kosu.end() || value - hanni_kosu[key] > 0) ans += 1;
        }

        if (debug) {
            cout << "---hannikosuu---" << endl;
            for (auto it = hanni_kosu.begin(); it != hanni_kosu.end(); ++it) {
                cout << "key:" << it->first << " value:" << it->second << endl;
            }
            cout << "i:" << i << " j:" << 0 << " ans:" << ans << endl;
        } else
            cout << ans << " ";

        for (int j = 1; j <= width - w; ++j) {
            // 横に移動
            for (int ii = i; ii < i + h; ++ii) {
                // hanni_kosu[masu[ii][j - 1]] = max(hanni_kosu[masu[ii][j - 1]] - 1, 0);
                hanni_kosu[masu[ii][j - 1]] -= 1;
                hoge = masu[ii][j + w - 1];
                if (hanni_kosu.find(hoge) != hanni_kosu.end())
                    hanni_kosu[hoge] += 1;
                else
                    hanni_kosu[hoge] = 1;
            }

            ans = 0;
            for (auto it = zentai_kosu.begin(); it != zentai_kosu.end(); ++it) {
                key   = it->first;
                value = it->second;
                if (hanni_kosu.find(key) == hanni_kosu.end() || value - hanni_kosu[key] > 0) ans += 1;
            }

            if (debug) {
                cout << "---hannikosuu---" << endl;
                for (auto it = hanni_kosu.begin(); it != hanni_kosu.end(); ++it) {
                    cout << "key:" << it->first << " value:" << it->second << endl;
                }
                cout << "i:" << i << " j:" << j << " ans:" << ans << endl;
            } else
                cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}
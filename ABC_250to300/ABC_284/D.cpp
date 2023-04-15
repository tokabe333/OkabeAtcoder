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

#include <iostream>
#include <utility> // std::swap()
#include <vector>

// Union-Find 木 (1.4 高速化 + 省メモリ化)
typedef long long int uf_type;
class UnionFind {
  public:
    UnionFind() = default;

    // n 個の要素
    explicit UnionFind(size_t n)
        : m_parentsOrSize(n, -1) {}

    // i の root を返す
    uf_type find(uf_type i) {
        if (m_parentsOrSize[i] < 0) {
            return i;
        }

        // 経路圧縮
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }

    // a の木と b の木を統合
    void merge(uf_type a, uf_type b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size (小さいほうが子になる）
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                std::swap(a, b);
            }

            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }

    // a と b が同じ木に属すかを返す
    bool connected(uf_type a, uf_type b) {
        return (find(a) == find(b));
    }

    // i が属するグループの要素数を返す
    uf_type size(uf_type i) {
        return -m_parentsOrSize[find(i)];
    }

  private:
    // m_parentsOrSize[i] は i の 親,
    // ただし root の場合は (-1 * そのグループに属する要素数)
    std::vector<uf_type> m_parentsOrSize;
};

int main() {
    bool debug = true;
    ll   t;
    cin >> t;

    ll cb = cbrt(pow(10, 18) * 9) + 10;

    // エラトス
    vll prime(cb, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i < prime.size(); ++i) {
        if (prime[i] == 0) continue;
        int index = i + i;
        while (index < prime.size()) {
            prime[index] = 0;
            index += i;
        }
    }

    rep(hoge, t) {
        ll n;
        cin >> n;
        for (ll i = 0; i < prime.size(); ++i) {
            if (prime[i] == 0) continue;
            // p2の場合
            ll p2 = i * i;
            if (n % p2 == 0) {
                cout << i << " " << n / p2 << endl;
                break;
            }

            // qの場合
            if (n % i != 0) continue;
            ll n2   = n / i;
            ll gaba = round(sqrt(n2));
            if (gaba * gaba == n2) {
                cout << gaba << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}
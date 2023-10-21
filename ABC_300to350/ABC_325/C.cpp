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

// Union-Find 木 (1.4 高速化 + 省メモリ化)
typedef int uf_type;
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
    preprocess();
    int h, w;
    cin >> h >> w;

    vvi masu(h, vi(w, 0));

    UnionFind uf(h * w);
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if (s[j] == '#') masu[i][j] = 1;
        }
    }

    // printvvec(masu);

    rep(i, h) {
        rep(j, w) {
            if (masu[i][j] == 0) continue;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dy == 0 && dx == 0) continue;
                    int y = i + dy;
                    int x = j + dx;
                    if (y < 0 || h <= y || x < 0 || w <= x) continue;
                    if (masu[i][j] == 0 || masu[y][x] == 0) continue;
                    uf.merge(i * w + j, y * w + x);
                    //   printf("i:%d j:%d y:%d x:%d\n", i, j, y, x);
                }
            }
        }
    }

    set<int> si;
    rep(i, h * w) {
        si.insert(uf.find(i));
    }
    int ans = 0;
    for (auto itr = si.begin(); itr != si.end(); ++itr) {
        int y = (*itr) / w;
        int x = (*itr) % w;
        if (masu[y][x] == 1) {
            // printf("y:%d x:%d\n", y, x);
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
} // end of main

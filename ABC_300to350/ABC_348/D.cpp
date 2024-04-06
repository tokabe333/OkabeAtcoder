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

const bool debug = true;

bool flag[1000];

bool dfs(const vector<unordered_set<int>> &graph, int n, int node) {
    if (n == node) return true;
    if (flag[node]) return false;
    flag[node] = true;

    bool ret = false;
    for (auto g : graph[node]) {
        bool hoge = dfs(graph, n, g);
        if (hoge) ret = true;
    }
    return true;
}

int main() {
    preprocess();

    int h, w, n, sy, sx, gy = 1, gx = -1, startDrag = -1, goaldrag = -1;
    cin >> h >> w;
    vvb masu(h, vb(w, true));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if (s[j] == 'S') {
                sy = i;
                sx = j;
            } else if (s[j] == 'T') {
                gy = i;
                gx = j;
            } else if (s[j] == '#') {
                masu[i][j] = false;
            }
        }
    }

    cin >> n;
    vvi drags(n, vi(3, 0));
    vvi dragmasu(h, vi(w, 0));
    rep(i, n) {
        int y, x, e;
        cin >> y >> x >> e;
        --y;
        --x;
        if (y == sy && x == sx) startDrag = i;
        if (y == gy && x == gx) goaldrag = i;
        drags[i][0]    = y;
        drags[i][1]    = x;
        drags[i][2]    = e;
        dragmasu[y][x] = i + 1;
    }

    if (goaldrag == -1) {
        dragmasu[gy][gx] = n + 1;
        goaldrag         = n;
    }

    if (startDrag == -1) {
        cout << "No" << endl;
        return 0;
    }

    UnionFind uf(n + 2);
    rep(i, n) {
        unordered_map flag;
        queue<vi>     que;
        que.push({drags[i][0], drags[i][1], drags[i][2]});
        while (que.empty() != true) {
            int y = que.front()[0];
            int x = que.front()[1];
            int e = que.front()[2];
            que.pop();

            if (flag.find(pii(y, x)) != flag.end()) continue;
            flag.insert(pii(y, x));

            if (dragmasu[y][x] > 0) {
                uf.merge(i, dragmasu[y][x] - 1);
            }

            if (e == 0) continue;

            // up, down, left, right
            if (0 < y && masu[y - 1][x]) que.push({y - 1, x, e - 1});
            if (y < h - 1 && masu[y + 1][x]) que.push({y + 1, x, e - 1});
            if (0 < x && masu[y][x - 1]) que.push({y, x - 1, e - 1});
            if (x < w - 1 && masu[y][x + 1]) que.push({y, x + 1, e - 1});
        }
    }

    if (uf.connected(startDrag, goaldrag))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
} // end of main

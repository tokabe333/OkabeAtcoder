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

struct unchi {
  public:
    int x, y, d;
    unchi(){};
    unchi(int yy, int xx, int dd) {
        this->y = yy;
        this->x = xx;
        this->d = dd;
    }
};

int main() {
    preprocess();

    int n;
    cin >> n;

    vector<pii> dist(4);
    dist[0] = {0, 1};
    dist[1] = {1, 0};
    dist[2] = {0, -1};
    dist[3] = {-1, 0};

    vvi masu(n, vi(n, -1));
    masu[(n + 1) / 2 - 1][(n + 1) / 2 - 1] = -3;

    queue<unchi> que;
    que.push(unchi(0, 0, 1));
    int muki = 0;
    while (que.empty() == false) {
        unchi now = que.front();
        que.pop();
        int y = now.y;
        int x = now.x;
        int d = now.d;

        masu[y][x] = d;

        int dy = dist[muki].first;
        int dx = dist[muki].second;

        //    printf("y:%d x:%d d:%d dy:%d dx:%d\n", y, x, d, dy, dx);

        if (y + dy < 0 || n <= y + dy || x + dx < 0 || n <= x + dx ||
            masu[y + dy][x + dx] != -1) {
            muki = (muki + 1) % 4;
            dy   = dist[muki].first;
            dx   = dist[muki].second;
        }

        if (masu[y + dy][x + dx] == -3) break;

        que.push(unchi(y + dy, x + dx, d + 1));
        // printvvec(masu);
        // cout << endl;
    }

    rep(i, n) {
        rep(j, n) {
            if (masu[i][j] != -3)
                cout << masu[i][j] << " ";
            else
                cout << "T ";
        }
        cout << "\n";
    }

    return 0;
} // end of main

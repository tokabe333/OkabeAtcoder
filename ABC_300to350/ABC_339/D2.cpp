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

int main() {
    preprocess();

    int n;
    cin >> n;
    int p1 = -1;
    int p2 = -1;

    // 0→秋、1→壁
    vvi masu(n, vi(n, 0));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, n) {
            if (s[j] == 'P') {
                if (p1 == -1) {
                    p1 = i * n + j;
                } else {
                    p2 = i * n + j;
                }

            } else if (s[j] == '#') {
                masu[i][j] = 1;
            }
        }
    }

    vvi flag(61 * 61, vi(61 * 61, 0));

    queue<vi> que;
    que.push({0, p1, p2});
    while (true) {
        cout << que.size() << "  ";
        int depth = que.front()[0];
        int p1    = que.front()[1];
        int p2    = que.front()[2];
        que.pop();
        if (flag[p1][p2] == 1) continue;
        if (depth == 60) continue;
        flag[p1][p2] = 1;

        int p1y = p1 / n;
        int p1x = p1 % n;
        int p2y = p2 / n;
        int p2x = p2 % n;

        // ue
        int ue1 = 0 < p1y && masu[p1y - 1][p1x] == 0 ? p1y - 1 : p1y;
        int ue2 = 0 < p2y && masu[p2y - 1][p2x] == 0 ? p2y - 1 : p2y;
        que.push({depth + 1, ue1 * n + p1x, ue2 * n + p2x});

        // sita
        int sita1 = p1y < n - 1 && masu[p1y + 1][p1x] == 0 ? p1y + 1 : p1y;
        int sita2 = p2y < n - 1 && masu[p2y + 1][p2x] == 0 ? p2y + 1 : p2y;
        que.push({depth + 1, sita1 * n + p1x, sita2 * n + p2x});

        // hidari
        int hi1 = 0 < p1x && masu[p1y][p1x - 1] == 0 ? p1x - 1 : p1x;
        int hi2 = 0 < p2x && masu[p2y][p2x - 1] == 0 ? p2x - 1 : p2x;
        que.push({depth + 1, p1y * n + hi1, p2y * n + hi2});

        // migi
        int mi1 = p1x < n - 1 && masu[p1y][p1x + 1] == 0 ? p1x + 1 : p1x;
        int mi2 = p2x < n - 1 && masu[p2y][p2x + 1] == 0 ? p2x + 1 : p2x;
        que.push({depth + 1, p1y * n + mi1, p2y * n + mi2});
    }

    return 0;
} // end of main

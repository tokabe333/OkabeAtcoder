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

// lð16Å\¦(ë·ªµµ¢âèÉÎ)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flushÍd½¢)
#define elnf "\n"

// £vpÂ«ZbeBO
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
#define Y first
#define X second

struct Data {
    int depth;
    pii p1;
    pii p2;
    Data() {}
    Data(int d, pii pp, pii ppp) {
        depth = d;
        p1    = pp;
        p2    = ppp;
    }
};

int main() {
    preprocess();

    int n;
    cin >> n;
    vector<pii> player;

    // 0¨HA1¨ÇA2¨P
    vvi masu(n, vi(n, 0));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, n) {
            if (s[j] == 'P') {
                player.push_back({i, j});
            } else if (s[j] == '#') {
                masu[i][j] = 1;
            }
        }
    }

    queue<Data> que;
    que.push(Data(0, player[0], player[1]));
    while (true) {
        int depth = que.front().depth;
        pii p1    = que.front().p1;
        pii p2    = que.front().p2;
        que.pop();

        // printf("depth:%d p1:{%d, %d} p2:{%d, %d}\n", depth, p1.Y + 1, p1.X + 1, p2.Y + 1, p2.X + 1);

        if (p1.Y == p2.Y && p1.X == p2.X) {
            cout << depth << endl;
            return 0;
        }

        // ã
        pii ue1 = p1;
        pii ue2 = p2;
        if (1 < ue1.Y && masu[ue1.Y - 1][ue1.X] == 0) ue1.Y -= 1;
        if (1 < ue2.Y && masu[ue2.Y - 1][ue2.X] == 0) ue2.Y -= 1;
        que.push(Data(depth + 1, ue1, ue2));

        // º
        pii sita1 = p1;
        pii sita2 = p2;
        if (sita1.Y < n - 1 && masu[sita1.Y + 1][sita1.X] == 0) sita1.Y += 1;
        if (sita2.Y < n - 1 && masu[sita2.Y + 1][sita2.X] == 0) sita2.Y += 1;
        que.push(Data(depth + 1, sita1, sita2));

        // ¶
        pii hi1 = p1;
        pii hi2 = p2;
        if (1 < hi1.X && masu[hi1.Y][hi1.X - 1] == 0) hi1.X -= 1;
        if (1 < hi2.X && masu[hi2.Y][hi2.X - 1] == 0) hi2.X -= 1;
        que.push(Data(depth + 1, hi1, hi2));

        // ¶
        pii migi1 = p1;
        pii migi2 = p2;
        if (migi1.X < n - 1 && masu[migi1.Y][migi1.X - 1] == 0) migi1.X -= 1;
        if (migi2.X < n - 1 && masu[migi2.Y][migi2.X - 1] == 0) migi2.X -= 1;
        que.push(Data(depth + 1, migi1, migi2));
    }

    return 0;
} // end of main

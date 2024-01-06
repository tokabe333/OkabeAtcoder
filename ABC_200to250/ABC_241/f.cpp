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

const bool debug = false;

struct Unchi {
  public:
    ll X, Y, D;
    Unchi() {}
    Unchi(ll x, ll y, ll d) : X(x), Y(y), D(d) {}
};

int main() {
    preprocess();
    ll h, w, n;
    cin >> h >> w >> n;
    ll sx, sy;
    cin >> sx >> sy;
    ll gx, gy;
    cin >> gx >> gy;
    unordered_map<ll, set<ll>> xs;
    unordered_map<ll, set<ll>> ys;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        xs[x].insert(y);
        ys[y].insert(x);
    }
    // ゴールの上下左右に障害物があるか
    bool goal = false;
    if (xs[gx - 1].count(gy) == 1) goal = true;
    if (xs[gx + 1].count(gy) == 1) goal = true;
    if (ys[gy - 1].count(gx) == 1) goal = true;
    if (ys[gy + 1].count(gx) == 1) goal = true;
    if (goal == false) {
        cout << -1 << endl;
        return 0;
    }

    queue<Unchi> q;
    q.push(Unchi(gx, gy, 0));
    map<pll, bool> visit;
    while (q.empty() == false) {
        Unchi now = q.front();
        q.pop();
        if (visit.count({now.X, now.Y}) > 0) continue;
        visit[{now.X, now.Y}] = true;
        // 上行くぜ
        if (xs[now.X].count(now.Y - 1) == 1) {
            if (debug) cout << "上に行けたぜ" << endl;
            // 同じ列（行）の行き止まり
            auto it = xs[now.X].upper_bound(now.Y);
            ll   ylim;
            if (it == xs[now.X].end()) {
                ylim = 1145141919810LL;
            } else {
                ylim = *it;
            }
            if (debug) cout << "ylim : " << ylim << endl;
            if (sx == now.X && now.Y <= sy && sy < ylim) {
                if (debug) cout << "上に行くと答えがあったぜ" << endl;
                if (debug) cout << "nowX,Y,D : " << now.X << " " << now.Y << " " << now.D << endl;
                if (sy == now.Y && sx == now.X) {
                    cout << now.D << endl;
                } else {
                    cout << now.D + 1 << endl;
                }
                return 0;
            }
            if (xs.count(now.X + 1) > 0 && xs[now.X + 1].size() > 0) {
                it = xs[now.X + 1].upper_bound(now.Y);
                while (it != xs[now.X + 1].end() && *it < ylim) {
                    q.push(Unchi(now.X, *it, now.D + 1));
                    it++;
                }
            }

            if (xs.count(now.X - 1) > 0 && xs[now.X - 1].size() > 0) {
                it = xs[now.X - 1].upper_bound(now.Y);
                while (it != xs[now.X - 1].end() && *it < ylim) {
                    q.push(Unchi(now.X, *it, now.D + 1));
                    it++;
                }
            }
        }
        // 下行くぜ
        if (xs[now.X].count(now.Y + 1) == 1) {
            if (debug) cout << "下に行けたぜ" << endl;
            auto it  = upper_bound(xs[now.X].rbegin(), xs[now.X].rend(), now.Y);
            auto itt = it;
            itt--;
            ll ylim;
            if (it == xs[now.X].rbegin()) {
                ylim = -1145141919810LL;
            } else {
                ylim = *itt;
            }
            if (debug) cout << "ylim : " << ylim << endl;
            if (debug) cout << "*it : " << *itt << endl;
            if (debug) cout << "dist : " << distance(xs[now.X].rbegin(), it) << endl;
            if (sx == now.X && now.Y >= sy && sy > ylim) {
                if (sy == now.Y && sx == now.X) {
                    cout << now.D << endl;
                } else {
                    cout << now.D + 1 << endl;
                }
                return 0;
            }
            if (xs.count(now.X + 1) > 0 && xs[now.X + 1].size() > 0) {
                it  = upper_bound(xs[now.X + 1].rbegin(), xs[now.X + 1].rend(), now.Y);
                itt = it;
                itt--;
                while (*itt > ylim) {
                    q.push(Unchi(now.X, *itt, now.D + 1));
                    if (it == xs[now.X + 1].rend()) {
                        break;
                    }
                    it++;
                }
            }
            if (xs.count(now.X - 1) > 0 && xs[now.X - 1].size() > 0) {
                it  = upper_bound(xs[now.X - 1].rbegin(), xs[now.X - 1].rend(), now.Y);
                itt = it;
                itt--;
                while (*itt > ylim) {
                    q.push(Unchi(now.X, *itt, now.D + 1));
                    if (it == xs[now.X - 1].rend()) {
                        break;
                    }
                    it++;
                }
            }

            if (debug) {
                cout << "q.size() :" << q.size() << endl;
                cout << "q.front :" << q.front().X << " " << q.front().Y << endl;
            }
        }
        // 左行くぜ
        if (ys[now.Y].count(now.X + 1) == 1) {
            if (debug) cout << "左に行けたぜ" << endl;
            auto it  = upper_bound(ys[now.Y].rbegin(), ys[now.Y].rend(), now.X);
            auto itt = it;
            itt--;
            ll xlim;
            if (it == ys[now.Y].rbegin()) {
                xlim = -1145141919810LL;
            } else {
                xlim = *itt;
            }
            if (debug) cout << "xlim : " << xlim << endl;
            if (debug) cout << "*it : " << *it << endl;
            if (debug) cout << "dist : " << distance(ys[now.Y].rbegin(), it) << endl;
            if (debug) {
                for (auto it : ys[now.Y])
                    cout << it << " ";
                cout << endl;
            }
            if (sy == now.Y && now.X >= sx && sx > xlim) {
                if (sy == now.Y && sx == now.X) {
                    cout << now.D << endl;
                } else {
                    cout << now.D + 1 << endl;
                }
                return 0;
            }
            if (ys.count(now.Y + 1) > 0 && ys[now.Y + 1].size() > 0) {
                it  = upper_bound(ys[now.Y + 1].rbegin(), ys[now.Y + 1].rend(), now.X);
                itt = it;
                itt--;
                while (*itt > xlim) {
                    q.push(Unchi(*itt, now.Y, now.D + 1));
                    if (it == ys[now.Y + 1].rend()) {
                        break;
                    }
                    it++;
                }
            }
            if (ys.count(now.Y - 1) > 0 && ys[now.Y - 1].size() > 0) {
                it  = upper_bound(ys[now.Y - 1].rbegin(), ys[now.Y - 1].rend(), now.X);
                itt = it;
                itt--;
                while (*itt > xlim) {
                    q.push(Unchi(*itt, now.Y, now.D + 1));
                    if (it == ys[now.Y - 1].rend()) {
                        break;
                    }
                    it++;
                }
            }

            if (debug) {
                cout << "q.size() :" << q.size() << endl;
                cout << "q.front :" << q.front().X << " " << q.front().Y << endl;
            }
        }
        // 右行くぜ”
        if (ys[now.Y].count(now.X - 1) == 1) {
            if (debug) cout << "右に行けたぜ" << endl;
            // 同じ列（行）の行き止まり
            auto it = ys[now.Y].upper_bound(now.X);
            ll   xlim;
            if (it == ys[now.Y].end()) {
                xlim = 1145141919810LL;
            } else {
                xlim = *it;
            }
            if (debug) cout << "xlim : " << xlim << endl;
            if (sy == now.Y && now.X <= sx && sx < xlim) {
                if (debug) cout << "右に行くと答えがあったぜ" << endl;
                if (debug) cout << "nowX,Y,D : " << now.X << " " << now.Y << " " << now.D << endl;
                if (sy == now.Y && sx == now.X) {
                    cout << now.D << endl;
                } else {
                    cout << now.D + 1 << endl;
                }
                return 0;
            }
            if (ys.count(now.Y + 1) > 0 && ys[now.Y + 1].size() > 0) {
                it = ys[now.Y + 1].upper_bound(now.X);
                while (it != ys[now.Y + 1].end() && *it < xlim) {
                    q.push(Unchi(*it, now.Y, now.D + 1));
                    it++;
                }
            }

            if (ys.count(now.Y - 1) > 0 && ys[now.Y - 1].size() > 0) {
                it = ys[now.Y - 1].upper_bound(now.X);
                while (it != ys[now.Y - 1].end() && *it < xlim) {
                    q.push(Unchi(*it, now.Y, now.D + 1));
                    it++;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
} // end of main

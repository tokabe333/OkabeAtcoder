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
#define m107            1000000007
#define m998            998244353

// 数値を16桁で表示(誤差が厳しい問題に対応)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush処理は重たい)
#define elnf "\n"

// 競プロ用環境セッティング
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

bool debug = true;

int main() {
    preprocess();
    int n, m;
    cin >> n >> m;

    vvi rope(n, vi(0));

    // ロープ結ぶ
    rep(i, m) {
        int  a, c;
        char b, d; // 結ばれてるかだけで色は要らない
        cin >> a >> b >> c >> d;
        a -= 1;
        c -= 1;
        rope[a].emplace_back(c);
        rope[c].emplace_back(a);
    } // end of for

    vb flag(n, false); // 未探索0 探索済み1

    // 線状の紐の端を探す
    ll line = 0;
    rep(i, n) {
        if (flag[i] == true) continue;
        // 両端が結ばれているなら輪 or 線の両端以外
        if (rope[i].size() == 2) continue;

        flag[i] = true;

        // 両端が結ばれていないなら線
        if (rope[i].size() == 0) {
            line += 1;
            continue;
        }

        // 線の端が見つかったのでもう一方の端まで探索済みに
        int current = i;
        while (true) {
            // 次のロープ
            if (flag[rope[current][0]] == false)
                current = rope[current][0];
            else
                current = rope[current][1];

            flag[current] = true;

            // 端に到達したら終わり
            if (rope[current].size() == 1) {
                line += 1;
                break;
            }
        } // end of while

    } // end of for

    // 未探索のロープは全て輪になっている
    // ↑と同じ要領で輪の個数を数える
    ll ring = 0;
    rep(i, n) {
        if (flag[i] == true) continue;
        flag[i] = true;

        // 両端が探索済み → 一周して元の位置に戻った
        int current = i;
        while (true) {
            // 次のロープ
            if (flag[rope[current][0]] == false)
                current = rope[current][0];
            else
                current = rope[current][1];

            flag[current] = true;

            // 端に到達したら終わり
            if (flag[rope[current][0]] == true && flag[rope[current][1]] == true) {
                ring += 1;
                break;
            }
        } // end of while

    } // end of for

    cout << ring << " " << line << endl;

    return 0;
} // end of main

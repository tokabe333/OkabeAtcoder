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
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod107(m) m % 1000000007
#define mod998(m) m % 998244353
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
typedef pair<ll, ll>                   pii;
typedef pair<ll, string>               pis;
typedef pair<string, ll>               psi;

/* 小数点n以下で四捨五入する */
double round_n(double number, int n) {
    if (n == 0)
        return number;

    else if (n > 0) {
        number = number * pow(10, n - 1); // 四捨五入したい値を10の(n-1)乗倍する。
        number = round(number);           // 小数点以下を四捨五入する。
        number /= pow(10, n - 1);         // 10の(n-1)乗で割る。
        return number;
    }

    else {
        number = number * pow(10, n);
        number = round(number);
        number = number * pow(10, -1 * n);
        return number;
    }
}
int main() {
    ll n;
    cin >> n;

    vvll vec(n, vll(2));
    rep(i, n) {
        ll a, b;
        scanf("%lld-%lld", &a, &b);
        a = a - (a % 5);
        if (b % 5 != 0) b = b + (5 - (b % 5));
        if (b % 100 == 60) b = round_n(b, -2);
        vec[i][0] = a;
        vec[i][1] = b;
    }

    // cout << endl;
    // rep(i, n) {
    //     cout << vec[i][0] << " - " << vec[i][1] << endl;
    // }
    // cout << endl;

    vector<bool> flag(2402, false);
    rep(i, n) {
        for (int j = vec[i][0]; j <= vec[i][1]; ++j) {
            flag[j] = true;
        }
    }

    int start = -1;
    // ll finish = -1;
    rep(i, 2402) {
        if (flag[i] == true && start == -1) {
            start = i;
        }
        if (flag[i] == false && start != -1) {
            printf("%04d-%04d\n", start, i - 1);
            start = -1;
        }
    }

    return 0;
}
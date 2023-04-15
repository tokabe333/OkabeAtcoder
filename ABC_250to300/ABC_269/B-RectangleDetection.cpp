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
typedef long long int              ll;
typedef vector<ll>                 vll;
typedef vector<vector<ll>>         vvll;
typedef vector<vector<vector<ll>>> vvvll;

int main() {
    vector<string> masu(12);
    rep(i, 10) {
        string str;
        cin >> str;
        masu[i + 1] = "." + str + ".";
    }
    masu[0]  = "............";
    masu[11] = "............";

    ll a, b, c, d;
    for (int i = 1; i < 12; ++i) {
        for (int j = 1; j < 12; ++j) {
            if (masu[i][j] == '.') continue;
            if (masu[i - 1][j] == '.' && masu[i][j - 1] == '.') {
                a = i;
                c = j;
            }
            if (masu[i + 1][j] == '.' && masu[i][j + 1] == '.') {
                b = i;
                d = j;
            }
        }
    }

    cout << a << " " << b << endl
         << c << " " << d << endl;

    return 0;
}
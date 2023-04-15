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
    ll h, w;
    cin >> h >> w;

    vector<string> masu(h);
    rep(i, h) {
        cin >> masu[i];
    }

    rep(x, w) {
        ll count = 0;
        rep(y, h) {
            if (masu[y][x] == '#') count += 1;
        }
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
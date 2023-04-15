#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
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
    ll x, y, z;
    cin >> x >> y >> z;

    // 壁とゴールが反対側なら最短，壁より内側なら最短
    if ((x / abs(x)) != (y / abs(y)) || (abs(x) < abs(y))) {
        cout << abs(x) << endl;
        return 0;
    }

    // 壁の無効にゴールとハンマーがある場合のみ到達不能
    if ((x < y && z < y) || (y < x && y < z)) {
        cout << -1 << endl;
        return 0;
    }

    // それ以外ならハンマーを拾ってゴールに行く
    cout << abs(x - z) + abs(z) << endl;

    return 0;
}
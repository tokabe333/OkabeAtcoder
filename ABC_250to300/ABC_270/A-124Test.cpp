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
    ll a, b;
    cin >> a >> b;

    ll c = 0;
    if (a & 1 || b & 1) c += 1;
    a >>= 1;
    b >>= 1;
    if (a & 1 || b & 1) c += 2;
    a >>= 1;
    b >>= 1;
    if (a & 1 || b & 1) c += 4;
    cout << c << endl;

    return 0;
}
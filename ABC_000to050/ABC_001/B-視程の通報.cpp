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
    double m;
    cin >> m;
    m /= 1000;

    if (m < 0.1) {
        cout << "00" << endl;
    } else if (m <= 5) {
        printf("%02ld\n", (ll)(m * 10));
    } else if (m <= 30) {
        printf("%02ld\n", (ll)(m + 50));
    } else if (m <= 70) {
        printf("%02ld\n", (ll)((m - 30) / 5 + 80));
    } else {
        cout << 89 << endl;
    }

    return 0;
}
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
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;

int main() {
    ll h, m;
    cin >> h >> m;

    ll current = h * 60 + m;
    while (true) {
        ll hour    = current / 60;
        ll minutes = current % 60;
        // cout << "hour:" << hour << " minutes:" << minutes << endl;

        ll hour2    = (hour / 10 * 10) + (minutes / 10);
        ll minutes2 = ((hour % 10) * 10) + (minutes % 10);
        if (0 <= hour2 && hour2 <= 23 && 0 <= minutes2 && minutes2 <= 59) {
            cout << hour << " " << minutes << endl;
            return 0;
        }

        current += 1;
        if (current == 24 * 60) current = 0;
    }

    return 0;
}
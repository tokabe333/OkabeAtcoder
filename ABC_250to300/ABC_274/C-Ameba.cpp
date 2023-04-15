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
    ll n;
    cin >> n;
    vector<ll> ameba(2 * n + 10, 0);

    rep(ii, n) {
        int i = ii + 1;
        ll  no;
        scanf("%lld", &no);

        ameba[2 * i]     = no;
        ameba[2 * i + 1] = no;
    }
    // rep(i, (2 * n + 2)) cout << ameba[i] << " ";
    // cout << endl;

    cout << 0 << endl;
    vector<ll> memo(2 * n + 10, -1);
    for (int i = 2; i <= 2 * n + 1; ++i) {
        ll current = i;
        ll count   = 0;
        while (true) {
            if (memo[current] != -1) {
                cout << memo[current] + count << endl;
                memo[i] = memo[current] + count;
                break;
            }

            if (current == 1) {
                cout << count << endl;
                memo[i] = count;
                break;
            }
            current = ameba[current];
            count += 1;
        }
    }

    return 0;
}
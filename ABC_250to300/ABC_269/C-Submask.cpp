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

vll ans;

void func(vll &flag, ll num, int depth) {
    // cout << "num:" << num << " depth:" << depth << endl;

    if (depth >= flag.size()) {
        ans.emplace_back(num);
        return;
    }

    func(flag, num, depth + 1);

    if (flag[depth] == 1) {
        ll next_num = num + (ll)pow(2, flag.size() - depth - 1);
        func(flag, next_num, depth + 1);
    }
}

int main() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll  keta = ceil(log2(n)) + 1;
    vll flag(keta);
    ll  tmp = n;
    rep(i, keta) {
        flag[keta - i - 1] = tmp % 2;
        tmp >>= 1;
    }

    // cout << keta << endl;
    // rep(i, keta) cout << flag[i] << " ";
    // cout << endl;

    func(flag, 0, 0);

    // cout << "ans:" << ans.size() << endl;
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }

    return 0;
}
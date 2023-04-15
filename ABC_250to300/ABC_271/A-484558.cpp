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
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main()
{
    ll     n, i = 0;
    string ans = "";
    cin >> n;
    while (n > 0) {
        ll   hoge = n % 16;
        char c;
        if (hoge < 10)
            c = ('0' + hoge);
        else
            c = ('A' + (hoge - 10));

        ans = c + ans;
        n   = n / 16;
    }

    if (ans.size() == 0)
        ans = "00" + ans;
    else if (ans.size() == 1)
        ans = '0' + ans;
    cout << ans << endl;

    return 0;
}
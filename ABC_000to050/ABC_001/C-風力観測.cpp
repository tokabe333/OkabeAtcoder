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
        cout << number << endl;
        number = round(number);
        number = number * pow(10, -1 * n);
        return number;
    }
}

int main() {
    double deg, dis;
    cin >> deg >> dis;
    deg /= 10.0;
    dis /= 60.0;

    // cout << " dis:" << dis << endl;
    dis = round_n(dis, 2);
    // cout << "dis:" << dis << endl;

    int kaze = 0;
    if (dis <= 0.2)
        kaze = 0;
    else if (0.3 <= dis && dis <= 1.5)
        kaze = 1;
    else if (dis <= 3.3)
        kaze = 2;
    else if (dis <= 5.4)
        kaze = 3;
    else if (dis <= 7.9)
        kaze = 4;
    else if (dis <= 10.7)
        kaze = 5;
    else if (dis <= 13.8)
        kaze = 6;
    else if (dis <= 17.1)
        kaze = 7;
    else if (dis <= 20.7)
        kaze = 8;
    else if (dis <= 24.4)
        kaze = 9;
    else if (dis <= 28.4)
        kaze = 10;
    else if (dis <= 32.6)
        kaze = 11;
    else if (32.7 <= dis)
        kaze = 12;

    if (kaze == 0) {
        cout << "C 0" << endl;
        return 0;
    }

    string dist = "N";
    if (348.75 <= deg || deg < 11.25)
        dist = "N";
    else if (11.25 <= deg && deg < 33.75)
        dist = "NNE";
    else if (deg < 56.25)
        dist = "NE";
    else if (deg < 78.75)
        dist = "ENE";
    else if (deg < 101.25)
        dist = "E";
    else if (deg < 123.75)
        dist = "ESE";
    else if (deg < 146.25)
        dist = "SE";
    else if (deg < 168.75)
        dist = "SSE";
    else if (deg < 191.25)
        dist = "S";
    else if (deg < 213.75)
        dist = "SSW";
    else if (deg < 236.25)
        dist = "SW";
    else if (deg < 258.75)
        dist = "WSW";
    else if (deg < 281.25)
        dist = "W";
    else if (deg < 303.75)
        dist = "WNW";
    else if (deg < 326.25)
        dist = "NW";
    else if (deg < 348.75)
        dist = "NNW";

    cout << dist << " " << kaze << endl;

    return 0;
}
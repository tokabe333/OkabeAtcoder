
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long int                  ll;
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<float, float>             pff;
typedef pair<double, double>           pdd;
typedef vector<bool>                   vb;
typedef vector<vector<bool>>           vvb;
typedef vector<vector<vector<bool>>>   vvvb;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<float>                  vf;
typedef vector<vector<float>>          vvf;
typedef vector<vector<vector<float>>>  vvvf;
typedef vector<double>                 vd;
typedef vector<vector<double>>         vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef vector<pii>                    vpii;
typedef vector<vector<pii>>            vvpii;
typedef vector<vector<vector<pii>>>    vvvpii;
typedef vector<pll>                    vpll;
typedef vector<vector<pll>>            vvpll;
typedef vector<vector<vector<pll>>>    vvvpll;
typedef unordered_map<char, char>      umcc;
typedef unordered_map<char, int>       umci;
typedef unordered_map<char, ll>        umcll;
typedef unordered_map<char, string>    umcs;
typedef unordered_map<int, char>       umic;
typedef unordered_map<int, int>        umii;
typedef unordered_map<int, ll>         umill;
typedef unordered_map<int, string>     umis;
typedef unordered_map<ll, ll>          umllll;
typedef unordered_map<ll, string>      umlls;
typedef unordered_map<string, char>    umsc;
typedef unordered_map<string, int>     umsi;
typedef unordered_map<string, ll>      umsll;
typedef unordered_set<char>            usc;
typedef unordered_set<int>             usi;
typedef unordered_set<ll>              usll;
typedef unordered_set<string>          uss;

const double PI = 3.141592653589793;
#define rep(i, n)       for (int i = 0; i < (int)(n); ++i)
#define repe(i, n)      for (int i = 0; i <= (int)(n); ++i)
#define rep1(i, n)      for (int i = 1; i < (int)(n); ++i)
#define rep1e(i, n)     for (int i = 1; i <= (int)(n); ++i)
#define repab(i, a, b)  for (int i = (a); i < (b); ++i)
#define repabe(i, a, b) for (int i = (a); i <= (b); ++i)
#define mod107(m)       m % 1000000007
#define mod998(m)       m % 998244353
const ll m107 = 1000000007;
const ll m998 = 998244353;

// ���l��16���ŕ\��(�덷�����������ɑΉ�)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush�����͏d����)
#define elnf "\n"

// ���v���p���Z�b�e�B���O
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

template <class T>
void printvec(const vector<T> &vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
} // end of func

template <class T>
void printvvec(const vector<T> &vec) {
    rep(i, vec.size()) {
        rep(j, vec[i].size()) cout << vec[i][j] << " ";
        cout << endl;
    }
} // end of func

const bool debug = true;

static const int max_n = pow(10, 7); // ����a_i�̍ő�̗v�f����ݒ肷��
int              seg_tree[2 * max_n];
int              n;

// ���������s���֐�
void init(int n_) {
    // ���S�񕪖؂ɂ��邽�߁A�f�[�^����2�̔{���ɂ���B
    n = 1;
    while (n < n_)
        n *= 2;

    // RMQ���l�������̂ŁA�Z�O�؂̊e�l��INT_MAX�ɐݒ肵�Ă���
    rep(i, 2 * n) seg_tree[i] = 0;
}

// index�Ԗڂ̒l��x�ɕύX����֐�
void update(int index, int x) {
    index += n - 1; // �ł����̃��C���[�ɂ����āA1�Ԗڂ̒l��seg_tree�̒��ł�n�Ԗڂ�����
    seg_tree[index] = x;
    while (index > 0) {
        index           = (index - 1) / 2; // �e�̃m�[�h��index
        seg_tree[index] = min(seg_tree[2 * index + 1], seg_tree[2 * index + 2]);
    }
}

// ���[a,b)�ɂ�����ŏ��l�����߂�֐�
// index��seg_tree�ɂ�����ԍ��ŁAleft,right��seg_tree[index]�̋�ԂɑΉ�
// query(a,b,0,0,n)�Ƃ��ČĂԂ��Ƃ��l����B
int query(int a, int b, int index, int left, int right) {
    // �l���悤�Ƃ��Ă����Ԃ��A[a,b)�ɑS���܂܂�Ȃ��Ȃ�AINT_MAX��Ԃ��āA����ɉe�����Ȃ��悤�ɂ���B
    if (a >= right || b <= left) return 0;

    // �l���悤�Ƃ��Ă����Ԃ�[a,b)�Ɋ��S�Ɋ܂܂�Ă���Ȃ�A���̒l��Ԃ��΂悢�B
    if (a <= left && b >= right) return seg_tree[index];

    // �ǂ���ł��Ȃ��ꍇ�Aseg_tree[index]��2�̎q�m�[�h�ɑ΂��čċA�I�ɑ�����s���B
    int value_1 = query(a, b, 2 * index + 1, left, (left + right) / 2);
    int value_2 = query(a, b, 2 * index + 2, (left + right) / 2, right);
    return min(value_1, value_2);
}

int main() {
    preprocess();

    int nn, d;
    cin >> nn >> d;
    vi arr(nn);
    rep(i, nn) cin >> arr[i];

    n = 5 * pow(10, 5) + 10;
    init(n);

    rep(i, nn) {
        int sita = max(0, arr[i] - d);
        int ue   = min(n, arr[i] + d);

        int tibi = query(sita, ue + 1, 0, 0, n);
        // printf("sita:%d ue:%d tibi:%d\n", sita, ue, tibi);

        update(arr[i], tibi - 1);
        // tibi = query(sita, ue + 1, 0, 0, n);
        // printf("sita:%d ue:%d tibi:%d\n\n", sita, ue, tibi);
    }

    cout << (-1) * query(0, n, 0, 0, n) << endl;

    return 0;
} // end of main

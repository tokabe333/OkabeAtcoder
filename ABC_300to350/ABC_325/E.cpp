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
typedef pair<int, int>                 pii;
typedef pair<int, string>              pis;
typedef pair<string, int>              psi;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
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
void printvec(vector<T> vec) {
    rep(i, vec.size()) cout << vec[i] << " ";
    cout << endl;
} // end of func

template <class T>
void printvvec(vector<T> vec) {
    rep(i, vec.size()) {
        rep(j, vec[i].size()) cout << vec[i][j] << " ";
        cout << endl;
    }
} // end of func

const bool debug = true;

// ���ɍ��킹�ăo�C�g����ύX
typedef long long            dijint;
typedef pair<dijint, dijint> pdd;
typedef vector<dijint>       vdi;
typedef vector<pdd>          vpdd;
typedef vector<vector<pdd>>  vvpdd;

/// @brief �_�C�N�X�g���@�ł���n�_����S�Ẵm�[�h�܂ł̋�����T��
/// @param graph
/// @param start
/// @return ������񋓂����z��
vdi dijkstra(const vvpdd &graph, int start) {
    // �ϐ��p��
    int n = graph.size();

    // �Ƃ肠�����ő�l
    dijint MAX = sizeof(dijint) == 4 ? INT_MAX : LLONG_MAX;

    // ��������ێ�����D��x�t���L���[
    priority_queue<pdd, vpdd, greater<pdd>> pque;

    // �m�肵��������ێ�����return�p�ϐ�
    vdi distance(n, MAX);
    distance[start] = 0;
    pque.push(pdd(0, start));
    while (pque.size() > 0) {
        dijint d = pque.top().first;  // start ���� u �܂ł̋���
        dijint u = pque.top().second; // ������m�肽���m�[�h
        pque.pop();

        // ���Ɋm�肵�������ȏ�Ȃ�X�V�]�n���Ȃ�
        if (distance[u] < d) continue;

        // �e�틗����ǉ�
        for (pdd next : graph[u]) {
            dijint cost      = next.first;
            dijint next_node = next.second;
            // �X�V�]�n���Ȃ��ꍇ�͎�
            if (distance[next_node] <= d + cost) continue;
            distance[next_node] = d + cost;
            pque.push(pdd(d + cost, next_node));
        } // end of for
    }     // end of while

    return distance;
} // end of func

int main() {
    preprocess();
    int n;
    ll  a, b, c;
    cin >> n >> a >> b >> c;

    vvll drr(n, vll(n));
    rep(i, n) {
        rep(j, n) cin >> drr[i][j];
    }

    return 0;
} // end of main

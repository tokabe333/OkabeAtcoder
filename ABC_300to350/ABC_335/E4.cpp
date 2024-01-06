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

// �L���񏄉�O���t(DAG:Directed Acyclic Graph)
// �אڍs��ɑ΂��ăg�|���W�J���\�[�g����
// �ł��Ȃ��ꍇ�͗v�f0�̔z���Ԃ�
vi topological_sort(const vvpii &graph) {
    // �m�[�h��
    const int n = graph.size();

    // �e�m�[�h�̓��������L�^
    vi input_nodes(n, 0);
    rep(i, n) {
        rep(j, graph[i].size()) {
            input_nodes[graph[i][j].second] += 1;
        }
    } // end of for

    // ���̖͂{����0�̃m�[�h���L�^
    queue<int> que;
    rep(i, n) {
        if (input_nodes[i] > 0) continue;
        que.push(i);
    } // end of for

    // �g�|���W�J���\�[�g�������ʂ��L�^����z��
    vi sorted_arr;

    // �菇1 : ��������0�̃m�[�h���L���[�ɒǉ�
    // �菇2 : �L���[����m�[�h�����o���\�[�g���ʂɒǉ�
    // �菇3 : �אڂ���m�[�h�̓�������-1
    // �菇4 : �菇1 ~ �菇3 ���J��Ԃ�
    while (que.empty() == false) {
        // �L���[������o��
        int v = que.front();
        que.pop();

        // �אڂ���m�[�h�̓�������-1
        // for (int next : graph[v]) {
        rep(i, graph[v].size()) {
            int next = graph[v][i].second;
            input_nodes[next] -= 1;
            // ��������0�Ȃ�m�[�h�ɒǉ�
            if (input_nodes[next] == 0) que.push(next);
        } // end of for

        // �\�[�g���ʂɒǉ�
        sorted_arr.emplace_back(v);
    } // end of while

    // �\�[�g�����m�[�h����grpah�̃m�[�h���ƈ�v����΃g�|���W�J���\�[�g����
    // ��v���Ȃ���΃g�|���W�J���\�[�g�ł��Ȃ��O���t
    // return sorted_arr.size() == n ? sorted_arr : vi(0);
    return sorted_arr;
} // end of func

const bool debug = true;

int main() {
    preprocess();

    int n, m;
    cin >> n >> m;
    vi arr(n);
    rep(i, n) cin >> arr[i];

    vvpii graph(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        if (arr[u] < arr[v]) graph[u].emplace_back(pii(-1, v));
        if (arr[u] == arr[v]) graph[u].emplace_back(pii(0, v));
        if (arr[v] < arr[u]) graph[v].emplace_back(pii(-1, u));
        if (arr[v] == arr[u]) graph[v].emplace_back(pii(0, u));
    }

    auto ret = topological_sort(graph);
    printvec(ret);
    return 0;
} // end of main

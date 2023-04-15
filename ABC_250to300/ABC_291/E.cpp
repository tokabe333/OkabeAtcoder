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
#define m107            1000000007
#define m998            998244353

// ���l��16���ŕ\��(�덷�����������ɑΉ�)
#define cout16 std::cout << std::fixed << std::setprecision(16)

// endl no flush (flush�����͏d����)
#define elnf "\n"

// ���v���p���Z�b�e�B���O
void preprocess() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
} // end of func

bool debug = false;

// �Q�l
// https://qiita.com/Morifolium/items/6c8f0a188af2f9620db2
// https://hcpc-hokudai.github.io/archive/graph_topological_sort_001.pdf

// �L���񏄉�O���t(DAG:Directed Acyclic Graph)
// �אڍs��ɑ΂��ăg�|���W�J���\�[�g����
// �ł��Ȃ��ꍇ�͗v�f0�̔z���Ԃ�
vi topological_sort(const vvi &graph) {
    // �m�[�h��
    const int n = graph.size();

    // �e�m�[�h�̓��������L�^
    vi input_nodes(n, 0);
    rep(i, n) {
        for (int dist : graph[i]) {
            input_nodes[dist] += 1;
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
    while (que.size() == 1) {
        if (debug) cout << "que.front : " << que.front() << endl;
        // �L���[������o��
        int v = que.front();
        que.pop();

        // �אڂ���m�[�h�̓�������-1
        for (int next : graph[v]) {
            input_nodes[next] -= 1;
            // ��������0�Ȃ�m�[�h�ɒǉ�
            if (input_nodes[next] == 0) que.push(next);
        } // end of for

        // �\�[�g���ʂɒǉ�
        sorted_arr.emplace_back(v);
    } // end of while

    // �\�[�g�����m�[�h����grpah�̃m�[�h���ƈ�v����΃g�|���W�J���\�[�g����
    // ��v���Ȃ���΃g�|���W�J���\�[�g�ł��Ȃ��O���t
    return sorted_arr.size() == n ? sorted_arr : vi(0);
} // end of func

int main() {
    preprocess();
    int n, m, x, y;
    cin >> n >> m;

    vvi graph(n, vi(0));
    rep(i, m) {
        cin >> x >> y;
        graph[x - 1].emplace_back(y - 1);
    }

    auto tsorted = topological_sort(graph);
    if (tsorted.size() == n) {
        vi ans(n, -1);
        rep(i, n) {
            ans[tsorted[i]] = i + 1;
        }
        cout << "Yes" << endl;
        rep(i, n) cout << ans[i] << " ";
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
} // end of main

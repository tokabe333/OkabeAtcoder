#include "../_CppTemplate.cpp"

typedef ll bf_type;
struct Edge {
    int     from;
    int     to;
    bf_type cost;
    Edge() {}
    Edge(int f, int t, bf_type c) : from(f), to(t), cost(c) {}
};

bool Bellman_Ford(vector<bf_type> &dist, const vector<Edge> &edges, int start_node = 0, int goal_node = -1) {
    // ���_��n�A�G�b�W��m
    int n = dist.size();
    int m = edges.size();

    // goal_node���w�肳��Ă��Ȃ���΁A�Ō�̃m�[�h�Ɏw��
    if (goal_node == -1) goal_node = dist.size() - 1;

    // start_node����̋�����inf�ŏ�����
    bf_type inf                 = sizeof(bf_type) == 4 ? INT_MAX : LLONG_MAX;
    rep(i, dist.size()) dist[i] = inf;
    dist[start_node]            = 0;

    // �e���_�͍��X1�񂵂��ʂ�Ȃ�
    vector<bool> posi(n, true); // ���̕H���o�p
    rep(i, n) {
        rep(j, m) {
            int     from = edges[j].from;
            int     to   = edges[j].to;
            bf_type cost = edges[j].cost;

            // �X�V����inf�̂Ƃ��́A�����B�_�̂��ߍX�V���Ȃ�
            if (dist[from] == inf) continue;
            // �X�V��̒l�������𖞂����Ȃ��ꍇ�͍X�V���Ȃ�
            if (dist[to] <= dist[from] + cost) continue;

            dist[to] = dist[from] + cost;

            // �œK���� n - 1��œ������(�e���_�͍��X1�񂵂��ʂ�Ȃ����Ƃ��)
            // �� n ��ڈȍ~���X�V����Ă���Ȃ�΁A���̕H������
            if (i >= n - 1) posi[from] = false;
        }
    }

    // start_node �� goal_node �̌o�H�Ԃɕ��̕H�����݂��邩���m�F
    // (���̕H�̓O���t��ɑ��݂��邪�A�o�H��ɂ͑��݂��Ȃ��p�^�[��������)
    rep(i, n) {
        rep(j, m) {
            int from = edges[j].from;
            int to   = edges[j].to;
            if (posi[from] == false) posi[to] = false;
        }
    }
    return posi[goal_node];
} // end of Bellman_Ford

#include "../_CppTemplate.cpp"

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
    while (que.empty() == false) {
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
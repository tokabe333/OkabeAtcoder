#include "../_CppTemplate.cpp"

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
    dijint MAX = sizeof(dijint) == 4 ? INT_MAX : LONG_MAX;

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

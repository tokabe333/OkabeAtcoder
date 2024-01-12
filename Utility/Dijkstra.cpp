#include "../_CppTemplate.cpp"

/// @brief �_�C�N�X�g���@�ł���n�_����S�Ẵm�[�h�܂ł̋�����T��
/// @param graph vector<vector<pair<cost, node>>> i�s�ځ����_i j��ځ�{����, ���̒��_}
/// @param start node
/// @return ������񋓂����z��
// ���ɍ��킹�ăo�C�g����ύX
template <class T>
vector<T> dijkstra(const vector<vector<pair<T, T>>> &graph, int start) {
    // �ϐ��p��
    int n = graph.size();

    // �Ƃ肠�����ő�l
    T MAX = sizeof(T) == 4 ? INT_MAX : LLONG_MAX;

    // ��������ێ�����D��x�t���L���[
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> pque;

    // �m�肵��������ێ�����return�p�ϐ�
    vector<T> distance(n, MAX);
    distance[start] = 0;
    pque.push(pair<T, T>(0, start));
    while (pque.size() > 0) {
        T d = pque.top().first;  // start ���� u �܂ł̋���
        T u = pque.top().second; // ������m�肽���m�[�h
        pque.pop();

        // ���Ɋm�肵�������ȏ�Ȃ�X�V�]�n���Ȃ�
        if (distance[u] < d) continue;

        // �e�틗����ǉ�
        for (auto next : graph[u]) {
            T cost      = next.first;
            T next_node = next.second;
            // �X�V�]�n���Ȃ��ꍇ�͎�
            if (distance[next_node] <= d + cost) continue;
            distance[next_node] = d + cost;
            pque.push(pair<T, T>(d + cost, next_node));
        } // end of for
    }     // end of while

    return distance;
} // end of func
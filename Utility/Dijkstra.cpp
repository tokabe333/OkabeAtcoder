#include "../_CppTemplate.cpp"

// 問題に合わせてバイト数を変更
typedef long long            dijint;
typedef pair<dijint, dijint> pdd;
typedef vector<dijint>       vdi;
typedef vector<pdd>          vpdd;
typedef vector<vector<pdd>>  vvpdd;

/// @brief ダイクストラ法である始点から全てのノードまでの距離を探索
/// @param graph
/// @param start
/// @return 距離を列挙した配列
vdi dijkstra(const vvpdd &graph, int start) {
    // 変数用意
    int n = graph.size();

    // とりあえず最大値
    dijint MAX = sizeof(dijint) == 4 ? INT_MAX : LONG_MAX;

    // 距離候補を保持する優先度付きキュー
    priority_queue<pdd, vpdd, greater<pdd>> pque;

    // 確定した距離を保持するreturn用変数
    vdi distance(n, MAX);
    distance[start] = 0;
    pque.push(pdd(0, start));
    while (pque.size() > 0) {
        dijint d = pque.top().first;  // start から u までの距離
        dijint u = pque.top().second; // 距離を知りたいノード
        pque.pop();

        // 既に確定した距離以上なら更新余地がない
        if (distance[u] < d) continue;

        // 各種距離を追加
        for (pdd next : graph[u]) {
            dijint cost      = next.first;
            dijint next_node = next.second;
            // 更新余地がない場合は次
            if (distance[next_node] <= d + cost) continue;
            distance[next_node] = d + cost;
            pque.push(pdd(d + cost, next_node));
        } // end of for
    }     // end of while

    return distance;
} // end of func

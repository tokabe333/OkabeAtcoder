#include <chrono>
#include <iostream>
#include <random>
#include <set>

int main() {
    const int N = 1000000; // 追加する要素の数

    // std::set インスタンスを生成
    std::set<int> sortedSet;

    // ランダムな整数を生成して std::set に追加
    std::random_device              rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> dis;

    for (int i = 0; i < N; ++i) {
        sortedSet.insert(dis(gen));
    }

    // ベンチマーク: 要素のランダムなアクセス
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        int  randomIndex = dis(gen);
        bool found       = sortedSet.find(randomIndex) != sortedSet.end();
    }

    auto end      = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "std::set ベンチマーク: " << duration.count() << " ミリ秒" << std::endl;

    return 0;
}
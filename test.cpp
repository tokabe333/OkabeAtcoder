#include <chrono>
#include <iostream>
#include <random>
#include <set>

int main() {
    const int N = 1000000; // �ǉ�����v�f�̐�

    // std::set �C���X�^���X�𐶐�
    std::set<int> sortedSet;

    // �����_���Ȑ����𐶐����� std::set �ɒǉ�
    std::random_device              rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> dis;

    for (int i = 0; i < N; ++i) {
        sortedSet.insert(dis(gen));
    }

    // �x���`�}�[�N: �v�f�̃����_���ȃA�N�Z�X
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < N; ++i) {
        int  randomIndex = dis(gen);
        bool found       = sortedSet.find(randomIndex) != sortedSet.end();
    }

    auto end      = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "std::set �x���`�}�[�N: " << duration.count() << " �~���b" << std::endl;

    return 0;
}
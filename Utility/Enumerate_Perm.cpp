#include <algorithm>
#include <functional>
#include <iostream>

void recursive_comb(int *indexes, int s, int rest,
                    std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCk�̑g�ݍ��킹�ɑ΂��ď��������s����
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

// nPn�̏���ɑ΂��ď��������s����
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++)
        indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

// nPk�̏���ɑ΂��ď��������s����
void foreach_permutation(int n, int k, std::function<void(int *)> f) {
    foreach_comb(n, k, [&](int *c_indexes) {
        foreach_permutation(k, [&](int *p_indexes) {
            int indexes[k];
            for (int i = 0; i < k; i++) {
                indexes[i] = c_indexes[p_indexes[i]];
            }
            f(indexes);
        });
    });
}

int main() {
    int N = 5;
    int K = 5;
    foreach_permutation(N, K, [N, K](int *indexes) {
        for (int i = 0; i < K; ++i) {
            std::cout << indexes[i] << ",";
        }
        std::cout << std::endl;
    });
}
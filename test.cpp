#include <functional>

#include <iostream>
using namespace std;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCk‚Ì‘g‚Ý‡‚í‚¹‚É‘Î‚µ‚Äˆ—‚ðŽÀs‚·‚é
void foreach_comb(int n, int k, std::function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

int nn = 28;
int kk = 8;
int main() {
    foreach_comb(nn, kk, [](int *indexes) {
        for (int i = 0; i < kk; ++i)
            cout << indexes[i] << " ";
        cout << endl;
    });
}
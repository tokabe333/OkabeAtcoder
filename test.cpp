#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
int main() {
    using namespace std;
    int N, M;
    cin >> N >> M;
    vector<long> L(N);
    for (int i = 0; i < N; ++i) {
        cin >> L[i];
        ++L[i]; // �擪�ɋ󔒂����Ă���
    }
    long lower = ranges::max(L) - 1;       // ������ max L[i] �ȏ�
    long upper = reduce(begin(L), end(L)); // ������ �� L[i] �ȉ�
    // �񕪒T��
    while (lower + 1 < upper) {
        long middle = (lower + upper) / 2;
        int  rows   = 1; // ���̍s��
        long length = 0; // �擪���牽�����ڂ�
        for (int i = 0; i < N; ++i) {
            length += L[i];        // �s�̖����ɒǉ����Ă݂�
            if (length > middle) { // �͂ݏo����
                ++rows;            // ���s����
                length = L[i];     // �擪�ɒǉ�
            }
        }
        if (rows > M)       // �c��������Ă��Ȃ����
            lower = middle; // ������ middle ���傫��
        else                // ����Ă����
            upper = middle; // ������ middle �ȉ�
    }
    // �������� 1 �������ďo��
    cout << upper - 1 << endl;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3;

    // {0, 1, ..., n-1} �̕����W���̑S�T��
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> s;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) { // �񋓂� i ���܂܂�邩
                s.emplace_back(i);
            }
        }

        cout << bit << ": {";
        for (int i = 0; i < (int)s.size(); ++i) {
            cout << s[i] << " ";
        }
        cout << "}" << endl;
    }
}
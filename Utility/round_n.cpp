#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

/* �����_n�ȉ��Ŏl�̌ܓ����� */
double round_n(double number, int n) {
    if (n == 0)
        return number;

    else if (n > 0) {
        number = number * pow(10, n - 1); // �l�̌ܓ��������l��10��(n-1)��{����B
        number = round(number);           // �����_�ȉ����l�̌ܓ�����B
        number /= pow(10, n - 1);         // 10��(n-1)��Ŋ���B
        return number;
    }

    else {
        number = number * pow(10, n);
        number = round(number);
        number = number * pow(10, -1 * n);
        return number;
    }
}
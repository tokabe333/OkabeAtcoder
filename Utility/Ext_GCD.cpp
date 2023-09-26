#include "../_CppTemplate.cpp"

// �g�����[�N���b�h�̌ݏ��@
// �Ԃ�l: a �� b �̍ő����
// ax + by = gcd(a, b) �𖞂��� (x, y) ���i�[�����
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
} // end of extGCD
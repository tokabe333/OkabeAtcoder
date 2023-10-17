#include "../_CppTemplate.cpp"

// �f�������������� a^n �̂Ƃ� pair(a, n);
template <class T>
vector<pair<T, T>> prime_division(T n) {
    vector<pair<T, T>> ret;
    for (T a = 2; a * a <= n; ++a) {
        if (n % a != 0) continue;
        T ex = 0;
        while (n % a == 0) {
            ex += 1;
            n /= a;
        }

        ret.emplace_back(pair<T, T>(a, ex));
    }

    if (n != 1) ret.emplace_back(pair<T, T>(n, 1));
    return ret;
} // end of prime_division;
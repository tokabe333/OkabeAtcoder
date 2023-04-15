#include <iostream>
#include <utility> // std::swap()
#include <vector>

// Union-Find �� (1.4 ������ + �ȃ�������)
typedef long long int uf_type;
class UnionFind {
  public:
    UnionFind() = default;

    // n �̗v�f
    explicit UnionFind(size_t n)
        : m_parentsOrSize(n, -1) {}

    // i �� root ��Ԃ�
    uf_type find(uf_type i) {
        if (m_parentsOrSize[i] < 0) {
            return i;
        }

        // �o�H���k
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }

    // a �̖؂� b �̖؂𓝍�
    void merge(uf_type a, uf_type b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size (�������ق����q�ɂȂ�j
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                std::swap(a, b);
            }

            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }

    // a �� b �������؂ɑ�������Ԃ�
    bool connected(uf_type a, uf_type b) {
        return (find(a) == find(b));
    }

    // i ��������O���[�v�̗v�f����Ԃ�
    uf_type size(uf_type i) {
        return -m_parentsOrSize[find(i)];
    }

  private:
    // m_parentsOrSize[i] �� i �� �e,
    // ������ root �̏ꍇ�� (-1 * ���̃O���[�v�ɑ�����v�f��)
    std::vector<uf_type> m_parentsOrSize;
};
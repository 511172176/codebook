#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 100000 + 5;

class DisjointSet {
public:
    std::vector<int> parent;

    // ��l�ƨìd���A�N�C�Ӹ`�I���ڳ]�m�� -1
    DisjointSet(int size) : parent(size, -1) {}

    // �d�䶰�X���ڡA�öi����|���Y
    int find(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = find(parent[x]);  // ���|���Y�A�N x �����s����ڸ`�I
    }

    // �N��Ӷ��X�X��
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;  // �N x ���ڳs���� y ����
        }
    }
};

int n, m;

int main() {
    int loop;
    scanf("%d", &loop);  // ���եΨҼƶq
    while (loop--) {
        scanf("%d%d", &n, &m);

        // ��l�ƨìd���A�j�p�� 2 * n�A�ΨӪ�ܼĹ����Y
        DisjointSet dsu(2 * n + 1);

        for (int i = 0; i < m; i++) {
            int a, b;
            char s[5];
            scanf("%s%d%d", s, &a, &b);

            if (s[0] == 'A') {  // �d�߬O�_�P�@�����μĹ�
                if (dsu.find(a) != dsu.find(b) && dsu.find(a) != dsu.find(b + n))
                    printf("Not sure yet.\n");
                else if (dsu.find(a) == dsu.find(b))
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            } else {  // �аO a �M b ���Ĺ�����
                if (dsu.find(a) != dsu.find(b + n)) {
                    dsu.unionSets(a, b + n);  // a ���ĤH�O b
                    dsu.unionSets(b, a + n);  // b ���ĤH�O a
                }
            }
        }
    }
    return 0;
}

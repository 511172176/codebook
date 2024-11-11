#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 100000 + 5;

class DisjointSet {
public:
    std::vector<int> parent;

    // 初始化並查集，將每個節點的根設置為 -1
    DisjointSet(int size) : parent(size, -1) {}

    // 查找集合的根，並進行路徑壓縮
    int find(int x) {
        if (parent[x] < 0)
            return x;
        return parent[x] = find(parent[x]);  // 路徑壓縮，將 x 直接連接到根節點
    }

    // 將兩個集合合併
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;  // 將 x 的根連接到 y 的根
        }
    }
};

int n, m;

int main() {
    int loop;
    scanf("%d", &loop);  // 測試用例數量
    while (loop--) {
        scanf("%d%d", &n, &m);

        // 初始化並查集，大小為 2 * n，用來表示敵對關係
        DisjointSet dsu(2 * n + 1);

        for (int i = 0; i < m; i++) {
            int a, b;
            char s[5];
            scanf("%s%d%d", s, &a, &b);

            if (s[0] == 'A') {  // 查詢是否同一幫派或敵對
                if (dsu.find(a) != dsu.find(b) && dsu.find(a) != dsu.find(b + n))
                    printf("Not sure yet.\n");
                else if (dsu.find(a) == dsu.find(b))
                    printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            } else {  // 標記 a 和 b 為敵對幫派
                if (dsu.find(a) != dsu.find(b + n)) {
                    dsu.unionSets(a, b + n);  // a 的敵人是 b
                    dsu.unionSets(b, a + n);  // b 的敵人是 a
                }
            }
        }
    }
    return 0;
}

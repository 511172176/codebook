//POJ1703
#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 100000 + 5;

int parent[maxn * 2];  // 並查集的根節點陣列，用來儲存每個節點的父節點

// 初始化並查集，將每個節點的根設置為 -1
void initializeDisjointSet(int size) {
    for (int i = 0; i < size; ++i) {
        parent[i] = -1;  // 將每個節點初始化為獨立集合
    }
}

// 查找集合的根，並進行路徑壓縮
int find(int x) {
    if (parent[x] < 0)  // 若 x 是根節點，則返回 x
        return x;
    return parent[x] = find(parent[x]);  // 路徑壓縮，將 x 直接連接到根節點
}

// 合併兩個集合，將 x 和 y 所在的集合合併
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;  // 將 x 的根連接到 y 的根
    }
}

// 處理查詢指令，判斷是否同一幫派或敵對
void handleQuery(int a, int b, int n) {
    if (find(a) != find(b) && find(a) != find(b + n)) {
        printf("Not sure yet.\n");
    } else if (find(a) == find(b)) {
        printf("In the same gang.\n");
    } else {
        printf("In different gangs.\n");
    }
}

// 處理合併指令，將 a 和 b 設置為敵對關係
void handleUnion(int a, int b, int n) {
    if (find(a) != find(b + n)) {
        unionSets(a, b + n);  // 將 a 的敵人設為 b
        unionSets(b, a + n);  // 將 b 的敵人設為 a
    }
}

int main() {
    int loop;
    scanf("%d", &loop);  // 測試用例數量
    while (loop--) {
        int n, m;
        scanf("%d%d", &n, &m);

        // 初始化並查集，大小為 2 * n，用來表示敵對關係
        initializeDisjointSet(2 * n + 1);

        for (int i = 0; i < m; i++) {
            int a, b;
            char command[5];
            scanf("%s%d%d", command, &a, &b);

            if (command[0] == 'A') {  // 查詢指令
                handleQuery(a, b, n);
            } else {  // 標記敵對關係
                handleUnion(a, b, n);
            }
        }
    }
    return 0;
}

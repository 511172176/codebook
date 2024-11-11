#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 10000;  // 最大節點數
vector<int> tree[N];  // 用來儲存樹的鄰接表
int parent[N];        // 紀錄每個節點的父節點
int depth[N];         // 紀錄每個節點的深度

// 深度優先搜尋 (DFS) 計算每個節點的深度
void DFS(int node, int dep) {
    depth[node] = dep;  // 設置當前節點的深度
    for (size_t i = 0; i < tree[node].size(); i++) {  // 遍歷所有子節點
        int child = tree[node][i];
        DFS(child, dep + 1);  // 遞迴處理子節點，深度加 1
    }
}

// 最近共同祖先 (LCA) 查找函數
int findLCA(int x, int y) {
    // 讓深度較大的節點向上移動，直到兩個節點在同一深度
    while (x != y) {
        if (depth[x] > depth[y]) {
            x = parent[x];  // x 上移到其父節點
        } else {
            y = parent[y];  // y 上移到其父節點
        }
    }
    return x;  // 返回最近共同祖先
}

int main() {
    int casenum, n, i, x, y;
    scanf("%d", &casenum);  // 輸入測試案例數量

    for (int num = 0; num < casenum; num++) {
        scanf("%d", &n);  // 輸入節點數
        for (i = 0; i < n; i++) tree[i].clear();  // 清空鄰接表
        memset(parent, -1, sizeof(parent));  // 初始化父節點為 -1

        // 輸入 n-1 條邊來建樹
        for (i = 0; i < n - 1; i++) {
            scanf("%d %d", &x, &y);
            x--; y--;  // 將節點編號轉為 0 開始的索引
            tree[x].push_back(y);  // 將 y 加入 x 的子節點中
            parent[y] = x;  // 樹中 y 的父節點為 x
        }

        // 找到樹的根節點 (父節點為 -1 的節點)
        int root = 0;
        for (i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
                break;
            }
        }

        DFS(root, 0);  // 從根節點開始進行先序遍歷，初始化深度

        // 查詢最近共同祖先
        scanf("%d %d", &x, &y);
        x--; y--;  // 將輸入的節點轉為 0 開始的索引
        int lca = findLCA(x, y);  // 找到最近共同祖先
        printf("%d\n", lca + 1);  // 輸出結果，轉回 1 開始的編號
    }

    return 0;
}

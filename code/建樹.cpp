// 使用 DFS 方式建立樹結構

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;  // 最大節點數
vector<int> tree[maxn];  // 用於存儲樹的鄰接表
bool visited[maxn];  // 記錄節點是否已被訪問

// 建立樹
void addEdge(int u, int v) {
    tree[u].push_back(v);
    tree[v].push_back(u);  // 因為是無向樹，雙向連接
}

// 深度優先搜索 (DFS) 建立樹
void dfs(int u) {
    visited[u] = true;
    for (int v : tree[u]) {
        if (!visited[v]) {
            cout << "Edge: " << u << " - " << v << endl;  // 輸出邊
            dfs(v);  // 繼續遞迴遍歷
        }
    }
}

int main() {
    int n = 5;  // 節點數

    // 建立樹的邊
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);

    // 從節點1開始遍歷樹
    dfs(1);

    return 0;
}

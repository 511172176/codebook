// 使用鄰接表建立圖

#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1005;  // 最大節點數
vector<pair<int, int>> graph[maxn];  // 用於存儲圖的鄰接表，pair 表示(鄰接點, 邊權重)

// 建立圖的邊 (有向圖)
void addEdge(int u, int v, int weight) {
    graph[u].push_back(make_pair(v, weight));  // 添加一條從 u 到 v 的有向邊，邊的權重為 weight
}

int main() {
    int n = 5;  // 節點數

    // 建立圖的邊
    addEdge(1, 2, 10);  // 節點1到節點2，權重為10
    addEdge(1, 3, 5);
    addEdge(2, 4, 3);
    addEdge(3, 5, 2);

    // 輸出圖的鄰接表
    for (int u = 1; u <= n; u++) {
        cout << "Node " << u << " connects to: ";
        for (auto edge : graph[u]) {
            cout << "(" << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}

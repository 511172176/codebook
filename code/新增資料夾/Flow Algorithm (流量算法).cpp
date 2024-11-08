// 使用 Ford-Fulkerson 演算法來解最大流問題。
// 利用增廣路徑不斷增加流量，直到無法找到更多的增廣路徑。

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

#define V 6  // 節點數，假設我們的圖有 6 個節點

// BFS 搜索增廣路徑，並填充 parent[] 用來存儲路徑
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];  // 記錄哪些節點已經被訪問
    fill(visited, visited + V, false);  // 初始化所有節點為未訪問

    queue<int> q;  // 使用 BFS 搜索
    q.push(s);
    visited[s] = true;
    parent[s] = -1;  // 將源節點的父節點設為 -1 表示根節點

    // 進行標準的 BFS 搜索
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {  // 只考慮殘餘流量大於 0 的邊
                if (v == t) {  // 如果找到增廣路徑
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;  // 沒有找到增廣路徑
}

// Ford-Fulkerson 演算法的主函數，計算 s 到 t 的最大流
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V];  // 殘餘圖
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];  // 初始化殘餘圖

    int parent[V];  // 用來儲存 BFS 找到的路徑
    int max_flow = 0;  // 初始化最大流為 0

    // 不斷找增廣路徑，直到找不到為止
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // 計算增廣路徑中的最小殘餘容量
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // 更新殘餘圖中的流量
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;  // 反向邊增加流量
        }

        max_flow += path_flow;  // 更新最大流
    }

    return max_flow;  // 返回最大流量
}

//POJ2387
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAX_N 1010
#define INF 1e9

using namespace std;

int w[MAX_N][MAX_N];     // 圖的權重矩陣
int d[MAX_N];            // 距離陣列，用於 Dijkstra 演算法
bool visited[MAX_N];     // 記錄節點是否已訪問
int n, m;                // n 表示節點數量，m 表示邊數量

// 使用 Dijkstra 演算法找從起點到各節點的最短路徑
void dijkstraShortestPath(int s) {   
    // 初始化距離和訪問狀態
    for (int i = 1; i <= n; ++i) {
        d[i] = INF;          // 將所有節點距離初始化為無限大
        visited[i] = false;  // 將所有節點標記為未訪問
    }
    d[s] = 0;                // 起始節點的距離設為 0

    // 主要迴圈：逐步擴展最短路徑
    for (int i = 1; i <= n; ++i) {
        int x = -1;
        // 找出距離最小的未訪問節點
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && (x == -1 || d[j] < d[x])) {
                x = j;
            }
        }
        visited[x] = true; // 將選中的節點標記為已訪問

        // 更新與節點 x 直接相連的其他未訪問節點的最短距離
        for (int j = 1; j <= n; ++j) {
            if (!visited[j] && w[x][j] != INF) { // 確保節點 j 未訪問且有路徑
                d[j] = min(d[j], d[x] + w[x][j]); // 更新最短距離
            }
        }
    }
}

int main() {
    scanf("%d%d", &m, &n); // 輸入邊數和節點數
    // 初始化權重矩陣，所有邊的初始權重設為無限大（無邊連接）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            w[i][j] = INF;
        }
    }

    // 讀取邊的資料，並考慮重邊情況，保留權重最小的邊
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); // 輸入邊的兩端節點和權重
        if (w[a][b] > c) {
            w[a][b] = w[b][a] = c; // 更新為最小權重，適用於無向圖
        }
    }

    dijkstraShortestPath(1); // 從節點 1 開始運行 Dijkstra 演算法

    printf("%d\n", d[n]); // 輸出從節點 1 到節點 n 的最短距離
    return 0;
}
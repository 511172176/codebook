//POJ1562
#include <iostream>
#include <cstring>
using namespace std;

int map[105][105];     // 儲存油田的圖形，1 表示油田，0 表示空地
int vis[105][105];     // 紀錄是否已訪問
int n, m;              // 圖形的行數和列數

// 初始化訪問標記的函式
void initializeVisited() {
    memset(vis, 0, sizeof(vis));  // 將訪問標記陣列清零
}

// 深度優先搜索 (DFS) 用於探測一個油田的連接範圍
void depthFirstSearch(int x, int y) {
    vis[x][y] = 1;  // 標記當前節點為已訪問

    // 探索所有 8 個方向
    if (x + 1 < n && !vis[x + 1][y] && map[x + 1][y]) depthFirstSearch(x + 1, y);          // 下
    if (x - 1 >= 0 && !vis[x - 1][y] && map[x - 1][y]) depthFirstSearch(x - 1, y);         // 上
    if (y + 1 < m && !vis[x][y + 1] && map[x][y + 1]) depthFirstSearch(x, y + 1);          // 右
    if (y - 1 >= 0 && !vis[x][y - 1] && map[x][y - 1]) depthFirstSearch(x, y - 1);         // 左
    if (x + 1 < n && y + 1 < m && !vis[x + 1][y + 1] && map[x + 1][y + 1]) depthFirstSearch(x + 1, y + 1);  // 右下
    if (x - 1 >= 0 && y - 1 >= 0 && !vis[x - 1][y - 1] && map[x - 1][y - 1]) depthFirstSearch(x - 1, y - 1);  // 左上
    if (x + 1 < n && y - 1 >= 0 && !vis[x + 1][y - 1] && map[x + 1][y - 1]) depthFirstSearch(x + 1, y - 1);  // 左下
    if (x - 1 >= 0 && y + 1 < m && !vis[x - 1][y + 1] && map[x - 1][y + 1]) depthFirstSearch(x - 1, y + 1);  // 右上
}

// 計算油田數量的函式
int countOilDeposits() {
    int count = 0;  // 用於儲存油田的總數量
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && map[i][j]) {  // 若節點未訪問且是油田
                depthFirstSearch(i, j);     // 執行 DFS 探索該油田
                count++;                    // 每探索一次，計算一個獨立的油田
            }
        }
    }
    return count;  // 返回油田的總數
}

int main() {
    char ch;
    while (cin >> n >> m) {       // 輸入圖形的大小
        if (n == 0 && m == 0) break;

        initializeVisited();       // 初始化訪問標記陣列

        // 填充圖形的數據
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> ch;
                map[i][j] = (ch == '@') ? 1 : 0;  // '@' 表示油田，'*' 表示空地
            }
        }

        int result = countOilDeposits();  // 計算油田數量
        cout << result << endl;           // 輸出油田的總數
    }
    return 0;
}

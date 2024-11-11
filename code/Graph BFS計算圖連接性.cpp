//POJ1562
#include <iostream>
#include <cstring>
using namespace std;

struct Position {
    int i, j;  // 網格位置
} bfsQueue[10000];  // BFS 的佇列，重新命名為 bfsQueue 避免與標準庫衝突

int m, n;            // 網格的行數 m 和列數 n
char map[101][101];  // 相鄰矩陣，'*' 表示牆，'@' 表示油田
int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };  // 8 個方向

// 初始化網格
void initializeMap() {
    memset(map, 0, sizeof(map));  // 將網格 map 初始化
}

// 執行 BFS 遍歷找到所有相連的油田
void performBFS(int startRow, int startCol) {
    int front = 0, rear = 1;  // 初始化 BFS 佇列的首尾指標
    bfsQueue[front].i = startRow;
    bfsQueue[front].j = startCol;
    map[startRow][startCol] = '*';  // 將起始點設為已訪問狀態

    while (front != rear) {
        int currentRow = bfsQueue[front].i;
        int currentCol = bfsQueue[front].j;
        front++;  // 出佇列，佇列首指標 +1

        // 探索 8 個可能方向
        for (int k = 0; k < 8; k++) {
            int newRow = currentRow + directions[k][0];
            int newCol = currentCol + directions[k][1];

            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && map[newRow][newCol] == '@') {
                bfsQueue[rear].i = newRow;
                bfsQueue[rear].j = newCol;
                map[newRow][newCol] = '*';  // 將新位置設為已訪問
                rear++;  // 進佇列，佇列尾指標 +1
            }
        }
    }
}

// 計算網格中所有獨立油田的數量
int countOilDeposits() {
    int oilCount = 0;  // 計算油田的總數
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '@') {  // 若找到新的油田
                oilCount++;          // 油田數量加一
                performBFS(i, j);    // 使用 BFS 探索整個油田區域並標記
            }
        }
    }
    return oilCount;  // 返回油田的總數量
}

int main() {
    while (scanf("%d %d", &m, &n) && m) {  // 重複讀取行數 m 和列數 n，直到 m 為 0
        initializeMap();                   // 初始化網格資料
        for (int i = 0; i < m; i++) {
            scanf("%s", map[i]);           // 讀取網格中的所有元素
        }
        int result = countOilDeposits();   // 計算所有的油田數量
        printf("%d\n", result);            // 輸出結果
    }
    return 0;
}

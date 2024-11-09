#include <iostream>
#include <cstring>
using namespace std;

struct Position {
    int i, j;  // 網格位置
} bfsQueue[10000];  // BFS 的佇列，重新命名為 bfsQueue 避免與標準庫衝突

int m, n;  // 網格的行數 m 和列數 n
char map[101][101];  // 相鄰矩陣，'*' 表示牆，'@' 表示油田
int a[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};  // 8 個方向的移動

void BFS(int i, int j) {
    int front = 0, rear = 1;  // 佇列的首尾標誌初始化
    bfsQueue[front].i = i;
    bfsQueue[front].j = j;
    map[i][j] = '*';  // 將起點設為無油狀態

    while (front != rear) {
        int ii = bfsQueue[front].i;
        int jj = bfsQueue[front].j;
        front++;  // 佇列首指標 +1

        for (int k = 0; k < 8; k++) {  // 8 個相鄰方向
            int t1 = ii + a[k][0];
            int t2 = jj + a[k][1];

            if (map[t1][t2] == '@') {  // 若 (t1, t2) 是油田
                bfsQueue[rear].i = t1;
                bfsQueue[rear].j = t2;
                map[t1][t2] = '*';  // 將 (t1, t2) 設為無油狀態
                rear++;  // 佇列尾指標 +1
            }
        }
    }
}

int main() {
    int i, j;
    int num;

    while (scanf("%d %d", &m, &n) && m) {  // 反覆輸入行數 m 和列數 n，直到 m 為 0
        num = 0;
        for (i = 0; i < m; i++)
            scanf("%s", map[i]);  // 自上而下，從左至右讀取每個網格

        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (map[i][j] == '@') {  // 若 (i, j) 為油田
                    num++;  // 不同的油田數量 +1
                    BFS(i, j);  // 透過 BFS 將 (i, j) 可達的所有油田設為無油狀態
                }

        printf("%d\n", num);  // 輸出油田數
    }

    return 0;
}

#include <iostream>
#include <cstring>
using namespace std;

int map[6][6]; // 無向圖的相鄰矩陣

// 產生無向圖的相鄰矩陣
void makemap() {
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i != j) map[i][j] = 1;
        }
    }
    map[4][1] = map[1][4] = 0;
    map[4][2] = map[2][4] = 0;
}

// 深度優先搜索，找到所有可能的存取路徑
void dfs(int x, int k, string s) {
    s += char(x + '0'); // 將當前節點 x 加入存取序列

    if (k == 8) { // 如果已完成一筆順序
        cout << s << endl;
        return;
    }

    for (int y = 1; y <= 5; y++) { // 依照節點順序訪問相鄰節點
        if (map[x][y]) {
            map[x][y] = map[y][x] = 0; // 設定邊為已訪問
            dfs(y, k + 1, s);          // 遞迴搜索
            map[x][y] = map[y][x] = 1; // 恢復邊的狀態
        }
    }
}

int main() {
    makemap(); // 產生無向圖的相鄰矩陣
    dfs(1, 0, ""); // 從節點 1 開始計算所有可能的存取順序
    return 0;
}

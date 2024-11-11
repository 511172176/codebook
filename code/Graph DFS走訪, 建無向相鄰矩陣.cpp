//UVA291
#include <iostream>
#include <cstring>
using namespace std;

int map[6][6];  // 定義無向圖的相鄰矩陣，節點編號從 1 到 5

// 初始化無向圖的相鄰矩陣
void initializeMap() {
    memset(map, 0, sizeof(map));  // 將矩陣所有元素設置為 0，表示無邊
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i != j) map[i][j] = 1;  // 除了自己，所有節點相鄰（設為 1 表示有邊）
        }
    }
    // 刪除節點間不相鄰的邊
    map[4][1] = map[1][4] = 0;
    map[4][2] = map[2][4] = 0;
}

// 使用 DFS 搜索所有可能的訪問路徑
void dfsTraversal(int currentNode, int depth, string path) {
    path += char(currentNode + '0');  // 將當前節點加入路徑中

    if (depth == 8) {  // 如果已遍歷 8 條邊，輸出該路徑
        cout << path << endl;
        return;
    }

    // 遍歷所有相鄰節點
    for (int nextNode = 1; nextNode <= 5; nextNode++) {
        if (map[currentNode][nextNode]) {  // 如果存在相鄰邊
            map[currentNode][nextNode] = map[nextNode][currentNode] = 0; // 標記邊為已訪問
            dfsTraversal(nextNode, depth + 1, path);  // 遞迴搜索相鄰節點
            map[currentNode][nextNode] = map[nextNode][currentNode] = 1; // 回溯，恢復邊的狀態
        }
    }
}

// 主函式
void runTraversal() {
    initializeMap();         // 初始化無向圖的相鄰矩陣
    dfsTraversal(1, 0, "");  // 從節點 1 開始，深度 0，初始路徑為空字串
}

int main() {
    runTraversal();
    return 0;
}

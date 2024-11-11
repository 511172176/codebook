//URAL1109
#include <iostream>
#include <cstring>
using namespace std;

const int V = 1100; // 節點最大數量

int n, m, k;        // n: A 集合的代表數, m: B 集合的代表數, k: 代表之間的配對數
int pre[V];         // 匹配儲存陣列，pre[j] 表示與 B 集合中 j 節點匹配的 A 集合節點
bool v[V];          // 訪問標記陣列，紀錄當前匹配過程中訪問過的 B 集合節點
bool a[V][V];       // 二分圖的鄰接矩陣，a[i][j] 表示 A 集合中的 i 與 B 集合中的 j 之間是否有邊

// DFS 尋找增廣路來進行最大匹配
bool dfs(int i) {
    for (int j = 1; j <= m; j++) {
        // 檢查節點 j 是否未訪問，且 i 和 j 之間有邊
        if (!v[j] && a[i][j]) {
            v[j] = 1; // 標記 j 為已訪問
            // 若 j 未匹配，或 j 的匹配節點可以找到其他匹配
            if (pre[j] == 0 || dfs(pre[j])) {
                pre[j] = i; // 設定 (i, j) 為匹配
                return true; // 匹配成功
            }
        }
    }
    return false; // 匹配失敗
}

// 計算二分圖的最小邊覆蓋數
int minEdgeCover() {
    memset(pre, 0, sizeof(pre)); // 初始化匹配儲存陣列
    int matchCount = 0;          // 匹配計數

    for (int i = 1; i <= n; i++) {
        memset(v, 0, sizeof(v)); // 初始化訪問標記陣列
        if (dfs(i)) matchCount++; // 若 i 可以匹配，則匹配計數增加
    }

    // 最小邊覆蓋數 = N + M - 最大匹配數
    return n + m - matchCount;
}

int main() {
    cin >> n >> m >> k; // 輸入 A 和 B 的代表數量以及配對數
    memset(a, 0, sizeof(a)); // 初始化鄰接矩陣為 0，表示無邊

    // 讀取配對資料並設置鄰接矩陣
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;  // 輸入 A 集合的代表 x 與 B 集合的代表 y 的配對
        a[x][y] = 1;    // 標記 i 與 j 之間有邊
    }

    // 計算二分圖的最小邊覆蓋數
    int result = minEdgeCover();

    // 輸出最小邊覆蓋數
    cout << result << endl;

    return 0;
}
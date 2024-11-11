//POJ1469
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[110][310]; // 二分圖的鄰接矩陣，a[i][j] 表示課程 i 和學生 j 之間的連接
int n, m;        // n 表示課程數量，m 表示學生數量
int vis[310];    // 訪問標記陣列，用於記錄當前匹配過程中訪問過的學生
int pre[310];    // 匹配陣列，pre[j] 表示與學生 j 匹配的課程

// 使用 DFS 尋找增廣路，試圖找到未匹配的課程
bool dfs(int x) {
    for (int t = 1; t <= m; ++t) {
        if (a[x][t] && !vis[t]) {        // 如果課程 x 與學生 t 有邊且學生 t 未訪問
            vis[t] = 1;                  // 將學生 t 標記為已訪問
            if (pre[t] == 0 || dfs(pre[t])) { // 若學生 t 尚未匹配或學生 t 原先匹配的課程可以找到替代路徑
                pre[t] = x;              // 設定 (x, t) 為匹配
                return true;             // 匹配成功
            }
        }
    }
    return false;                        // 匹配失敗
}

// 使用匈牙利算法進行二分圖的最大匹配
int maxBipartiteMatching() {
    memset(pre, 0, sizeof(pre)); // 初始化匹配儲存陣列 pre
    int matchCount = 0;          // 匹配計數器

    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis)); // 對每個課程重新初始化訪問標記陣列
        if (dfs(i)) matchCount++;    // 如果課程 i 可以匹配，匹配計數增加
    }
    return matchCount;               // 返回最大匹配數量
}

int main() {
    int T;
    scanf("%d", &T); // 輸入測試案例數量
    while (T--) {
        // 輸入課程和學生數量
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));    // 初始化二分圖的鄰接矩陣

        // 建立二分圖的鄰接矩陣
        for (int i = 1; i <= n; ++i) {
            int t;
            scanf("%d", &t);  // 輸入每門課程的學生數量
            while (t--) {
                int j;
                scanf("%d", &j);   // 輸入學生編號
                a[i][j] = 1;       // 標記課程 i 和學生 j 之間的連接
            }
        }

        // 使用匈牙利算法進行最大匹配
        int result = maxBipartiteMatching();

        // 檢查匹配數量是否等於課程數量
        if (result == n) {
            printf("YES\n"); // 若所有課程都能匹配，輸出 "YES"
        } else {
            printf("NO\n");  // 否則，輸出 "NO"
        }
    }
    return 0;
}
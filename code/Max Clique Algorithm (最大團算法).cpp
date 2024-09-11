// 最大團問題的求解：使用位元遮罩來計算最大團。
// 最大團指的是在無向圖中，一個最大完全子圖。

const int MAXN = 50;  // 節點數的最大限制
int n, adj[MAXN][MAXN];  // n 為節點數，adj 為鄰接矩陣
int maxCliqueSize = 0;  // 用來記錄找到的最大團的大小

// DFS 搜索來判斷最大團的大小
void dfs(int depth, int *now, int size) {
    if (depth == n) {  // 如果已經遍歷完所有節點
        maxCliqueSize = max(maxCliqueSize, size);  // 更新最大團大小
        return;
    }

    // 檢查當前節點 depth 是否可以加入到現有的團
    for (int i = 0; i < size; i++) {
        if (!adj[now[i]][depth]) return;  // 不是完全圖，返回
    }

    now[size] = depth;  // 將當前節點加入團
    dfs(depth + 1, now, size + 1);  // 繼續搜索加入當前節點的情況
    dfs(depth + 1, now, size);  // 搜索不加入當前節點的情況
}

// 主函數，計算最大團
int maxClique() {
    int now[MAXN];  // 用來存儲當前的團
    dfs(0, now, 0);  // 從第 0 層開始搜索
    return maxCliqueSize;  // 返回最大團的大小
}

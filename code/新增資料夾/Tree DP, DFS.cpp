#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

// 深度優先搜索進行動態規劃計算
void dfs(int u) {
    visited[u] = 1;  // 標記節點已訪問
    dp[u][0] = 0;  // 當前節點不選擇
    dp[u][1] = 1;  // 當前節點選擇

    // 遍歷所有相鄰節點
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (visited[v]) continue;
        dfs(v);  // 遞迴調用DFS
        dp[u][0] += dp[v][1];  // 當前節點不選擇時，子節點必須選擇
        dp[u][1] += min(dp[v][0], dp[v][1]);  // 當前節點選擇時，子節點可以選擇或不選擇
    }
}

int solve() {
    int ans = 0;
    memset(visited, 0, sizeof(visited));  // 初始化訪問數組
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        dfs(i);  // 對每個未訪問的節點進行DFS
        ans += min(dp[i][0], dp[i][1]);  // 計算最小選擇
    }
    return ans;
}

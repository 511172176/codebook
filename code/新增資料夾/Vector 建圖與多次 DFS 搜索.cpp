// Vector 建圖與多次 DFS 搜索
const int maxn = 1005;
vector<int> g[maxn], nodes[maxn];  // 建立鄰接表與節點集
int n, s, k, p[maxn];              // n為總節點數，s為起始節點，k為最大距離
bool c[maxn];                       // 節點是否被訪問過

void dfs1(int u, int f, int dist) {
    p[u] = f;  // 記錄父節點
    int nd = g[u].size();
    if (nd == 1 && dist > k) nodes[dist].push_back(u); // 遠距離節點加入
    for (int i = 0; i < nd; i++) {
        int v = g[u][i];
        if (v != f) dfs1(v, u, dist + 1);  // 遞迴進行DFS
    }
}

int solve() {
    int ans = 0;
    memset(c, false, sizeof(c));  // 初始化訪問數組
    for (int dist = (n - 1); dist > k; dist--) {
        for (int i = 0; i < nodes[dist].size(); i++) {
            int u = nodes[dist][i];
            if (c[u]) continue;
            int v = u;
            for (int j = 0; j < k; j++) v = p[v];
            dfs2(v, -1, 0);  // 執行DFS，標記被訪問過的節點
            ans++;
        }
    }
    return ans;
}

void dfs2(int u, int f, int d) {
    c[u] = true;  // 標記節點已訪問
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != f && d < k) dfs2(v, u, d + 1);  // 深度優先搜索
    }
}

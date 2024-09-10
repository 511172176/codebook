// SPFA 最短路徑算法
int dist[maxn];  // 存儲到達每個節點的最短距離
vector<pair<int, int>> E[maxn];  // 鄰接表存儲圖
bool vis[maxn];  // 訪問標記
int out[maxn];   // 用來檢測負環

bool spfa(int s, int n) {
    queue<int> Q;
    Q.push(s);  // 將起點s加入隊列
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        out[u]++;
        if (out[u] > n) return false; // 出現負權重環
        for (int j = 0; j < E[u].size(); j++) {
            int v = E[u][j].first;
            if (dist[v] > dist[u] + E[u][j].second) {  // 有更短的路徑
                dist[v] = dist[u] + E[u][j].second;
                if (vis[v]) continue;
                vis[v] = 1;
                Q.push(v);  // 將v加入隊列
            }
        }
    }
    return true;
}

//URAL1076
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

const int MAXN = 505;
const int INF = INT_MAX;

struct Edge {
    int to, cap, cost;
    Edge(int _to, int _cap, int _cost) : to(_to), cap(_cap), cost(_cost) {}
};

class MinCostMaxFlow {
private:
    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> dist, prev, prevEdge;
    vector<bool> inQueue;

    // 使用 SPFA 尋找最短路徑，並更新 dist 和 prev 陣列
    bool SPFA() {
        dist.assign(n + 1, INF);
        prev.assign(n + 1, -1);
        prevEdge.assign(n + 1, -1);
        inQueue.assign(n + 1, false);

        queue<int> q;
        q.push(s);
        dist[s] = 0;
        inQueue[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (int eid : adj[u]) {
                Edge& e = edges[eid];
                int v = e.to;

                // 如果邊有剩餘容量，且找到更短路徑
                if (e.cap > 0 && dist[v] > dist[u] + e.cost) {
                    dist[v] = dist[u] + e.cost;
                    prev[v] = u;
                    prevEdge[v] = eid;

                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        return dist[t] != INF;
    }

    // 沿增廣路徑增加流量
    int augment() {
        int minFlow = INF;
        for (int v = t; v != s; v = prev[v]) {
            Edge& e = edges[prevEdge[v]];
            minFlow = min(minFlow, e.cap);
        }

        for (int v = t; v != s; v = prev[v]) {
            Edge& e = edges[prevEdge[v]];
            e.cap -= minFlow;
            edges[prevEdge[v] ^ 1].cap += minFlow;
        }

        return minFlow * dist[t];
    }

public:
    MinCostMaxFlow(int _n) : n(_n) {
        adj.resize(n + 1);
    }

    // 增加一條帶容量和費用的邊到網路
    void addEdge(int from, int to, int cap, int cost) {
        adj[from].push_back(edges.size());
        edges.emplace_back(to, cap, cost);
        adj[to].push_back(edges.size());
        edges.emplace_back(from, 0, -cost);
    }

    // 求解最小費用最大流，返回最小費用
    int minCostMaxFlow(int _s, int _t) {
        s = _s;
        t = _t;
        int totalCost = 0;

        while (SPFA()) {  // 當存在增廣路徑時
            totalCost += augment(); // 增加流量並累計費用
        }

        return totalCost;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    MinCostMaxFlow mcmf(2 * n + 2); // 建立網路圖，包括 2*n 節點和虛擬源/匯點
    vector<vector<int>> cost(n + 1, vector<int>(n + 1));

    // 讀入成本矩陣，計算每個節點的成本差
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
            sum += cost[i][j];
        }
        for (int j = 1; j <= n; j++) {
            cost[i][j] = sum - cost[i][j]; // 調整成本使得每條邊的權值表示差異
        }
    }

    int s = 1, t = 2 * n + 2;

    // 建立二分圖到網路圖的映射
    for (int i = 1; i <= n; i++) {
        mcmf.addEdge(s, i + 1, 1, 0);            // 源點到左側節點
        mcmf.addEdge(i + n + 1, t, 1, 0);        // 右側節點到匯點

        for (int j = 1; j <= n; j++) {
            mcmf.addEdge(i + 1, j + n + 1, 1, cost[i][j]); // 左側節點到右側節點的連接
        }
    }

    cout << mcmf.minCostMaxFlow(s, t) << endl; // 計算最小費用最大流並輸出結果

    return 0;
}
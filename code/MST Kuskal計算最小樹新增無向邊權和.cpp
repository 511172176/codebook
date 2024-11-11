//POJ2421
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定義邊結構
struct Edge {
    int u;      // 起點
    int v;      // 終點
    int weight; // 權重
};

// 定義並查集（Union-Find）類別
class UnionFind {
private:
    vector<int> parent; // 父節點

public:
    // 建構子，初始化並查集，每個節點的父節點為自己
    UnionFind(int n) : parent(n + 1) { // 使用 1-based 索引
        for(int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // 查找集合，並進行路徑壓縮
    int find_set(int x) {
        if(parent[x] != x)
            parent[x] = find_set(parent[x]);
        return parent[x];
    }

    // 合併兩個集合
    void union_set(int x, int y) {
        int fx = find_set(x);
        int fy = find_set(y);
        if(fx != fy)
            parent[fx] = fy;
    }
};

// 比較兩條邊的權重，用於排序
bool compare_edges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// 計算最小生成樹總權重的函式
int calculateMSTWeight(int N, const vector<vector<int>> &P, int M, const vector<pair<int, int>> &preConnected) {
    // 初始化並查集
    UnionFind uf(N);

    // 將已經預先連接的邊加入並查集
    for(int i = 0; i < preConnected.size(); ++i) {
        int a = preConnected[i].first;
        int b = preConnected[i].second;
        uf.union_set(a, b);
    }

    // 收集所有可能的邊
    vector<Edge> edges;
    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) { // 確保 j > i 避免重複邊
            if(P[i][j] > 0) { // 只考慮權重大於 0 的邊
                Edge e;
                e.u = i;
                e.v = j;
                e.weight = P[i][j];
                edges.push_back(e);
            }
        }
    }

    // 對所有邊按照權重進行排序
    sort(edges.begin(), edges.end(), compare_edges);

    int total_weight = 0;
    // 遍歷所有邊，選擇不形成環路的邊加入 MST
    for(int i = 0; i < edges.size(); ++i) {
        Edge edge = edges[i];
        if(uf.find_set(edge.u) != uf.find_set(edge.v)) {
            uf.union_set(edge.u, edge.v);
            total_weight += edge.weight;
        }
    }

    return total_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // 提高輸入輸出效率

    int N;
    while(cin >> N) {  // 讀取節點數量
        // 讀取鄰接矩陣
        vector<vector<int>> P(N + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= N; i++) {  // 1-based 索引
            for(int j = 1; j <= N; j++) {
                cin >> P[i][j];
            }
        }

        // 讀取已經預連接的邊
        int M;
        cin >> M;
        vector<pair<int, int>> preConnected;
        for(int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            preConnected.push_back(make_pair(a, b));
        }

        // 計算最小生成樹的總權重
        int total_MST_weight = calculateMSTWeight(N, P, M, preConnected);

        // 輸出 MST 的總權重
        cout << total_MST_weight << "\n";
    }
    return 0;
}
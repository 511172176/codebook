#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 結構體表示邊及其權重
struct Edge {
    int u;
    int v;
    int weight;
};

// Union-Find (Disjoint Set Union - DSU) 類別
class UnionFind {
private:
    vector<int> parent;
public:
    // 初始化 DSU，節點數為 n
    UnionFind(int n) : parent(n + 1) { // 假設節點從 1 開始
        for(int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // 查找集合的根，並進行路徑壓縮
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

// 比較函式，用於排序邊
bool compare_edges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// 執行 Kruskal 演算法並返回最小生成樹的總權重
int kruskal(int N, vector<Edge> &edges, UnionFind &uf) {
    // 按權重對邊進行排序（從小到大）
    sort(edges.begin(), edges.end(), compare_edges);

    int total_weight = 0;
    for(int i = 0; i < edges.size(); ++i) {
        Edge edge = edges[i];
        // 如果邊的兩個節點屬於不同的集合，則加入最小生成樹
        if(uf.find_set(edge.u) != uf.find_set(edge.v)) {
            uf.union_set(edge.u, edge.v);
            total_weight += edge.weight;
        }
    }
    return total_weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // 使用 0 代替 nullptr

    int N;
    while(cin >> N) {  // 讀取節點數 N
        // 讀取鄰接矩陣
        vector<vector<int>> P(N + 1, vector<int>(N + 1, 0));
        for(int i = 1; i <= N; ++i) {  // 1-based indexing
            for(int j = 1; j <= N; ++j) {
                cin >> P[i][j];
            }
        }

        // 初始化 Union-Find
        UnionFind uf(N);

        // 讀取已經連接的邊數 M 並合併這些邊
        int M;
        cin >> M;
        for(int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            uf.union_set(a, b);
        }

        // 收集所有邊，避免重複（無向圖）
        vector<Edge> edges;
        for(int i = 1; i <= N; ++i) {
            for(int j = i + 1; j <= N; ++j) { // j 從 i+1 開始避免重複
                if(P[i][j] > 0) { // 假設 0 表示沒有邊
                    edges.push_back(Edge{ i, j, P[i][j] });
                }
            }
        }

        // 執行 Kruskal 演算法以計算最小生成樹的總權重
        int total_MST_weight = kruskal(N, edges, uf);

        // 使用 std::endl 以確保每個測試案例後立即輸出
        cout << total_MST_weight << endl;
    }
    return 0;
}

/*
範例輸入:
3
0 990 692
990 0 179
692 179 0
1
1 2

預期輸出:
179
*/

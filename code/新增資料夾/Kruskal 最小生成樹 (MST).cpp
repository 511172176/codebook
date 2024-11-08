// Kruskal MST (最小生成樹)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1005;  // 最大節點數

struct Point {
    int x, y;
};

struct Edge {
    int u, v;
    double cost;
    bool operator<(const Edge& e) const {
        return cost < e.cost;  // 按邊的權重排序
    }
};

int parent[maxn], rank[maxn];  // 並查集
Point points[maxn];  // 存儲每個點的座標
Edge e[maxn * maxn];  // 存儲所有邊
int m;  // 邊的數量

// 初始化並查集
void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// 路徑壓縮找根
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

// 合併兩個集合
bool uni(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
        return true;
    }
    return false;
}

// 計算兩個點之間的歐幾里得距離
double dist(int u, int v) {
    int dx = points[u].x - points[v].x;
    int dy = points[u].y - points[v].y;
    return sqrt(dx * dx + dy * dy);
}

// Kruskal 最小生成樹算法
double kruskal(int n) {
    init(n);
    sort(e, e + m);  // 按權重對邊排序

    double ans = 0;
    int edge_count = 0;
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v;
        if (uni(u, v)) {  // 如果 u 和 v 不在同一集合中
            ans += e[i].cost;
            if (++edge_count == n - 1) break;  // 當邊數達到 n-1 時停止
        }
    }
    return ans;  // 返回最小生成樹的總權重
}

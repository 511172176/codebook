#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 100002
using namespace std;

struct Edge {
    int next, tail;  // next 指向下一條邊，tail 表示當前邊的終點
} edge[MAXN];

struct NodeRange {
    int l, r;  // 節點的左右時間戳
} nodeRange[MAXN];

int head[MAXN], cnt = 1, fenwickTree[MAXN], values[MAXN];  // `head` 為鄰接表頭，`cnt` 為時間戳計數器

// 初始化
void initialize(int n) {
    memset(head, -1, sizeof(head[0]) * (n + 1));
    memset(fenwickTree, 0, sizeof(fenwickTree[0]) * (n + 1));
    memset(nodeRange, 0, sizeof(nodeRange[0]) * (n + 1));
}

// 新增一條邊至鄰接表
void addEdge(int u, int v, int edgeIndex) {
    edge[edgeIndex].tail = v;
    edge[edgeIndex].next = head[u];
    head[u] = edgeIndex;
}

// DFS 標記每個節點的時間戳
void DFS(int u) {
    nodeRange[u].l = cnt;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        DFS(edge[i].tail);
    }
    nodeRange[u].r = cnt++;
}

// Fenwick Tree 的低位元計算，用於更新和查詢操作
inline int lowbit(int x) {
    return x & -x;
}

// 更新 Fenwick Tree 中的位置值
void updateFenwick(int x, int delta) {
    for (int i = x; i < cnt; i += lowbit(i)) {
        fenwickTree[i] += delta;
    }
}

// 在 Fenwick Tree 中計算區間和
int queryFenwick(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += fenwickTree[i];
    }
    return sum;
}

// 初始化每個節點的權值
void initializeValues(int n) {
    for (int i = 1; i <= n; i++) {
        values[i] = 1;
        updateFenwick(i, 1);  // 每個節點初始值為 1
    }
}

// 翻轉節點的權值
void toggleValue(int x) {
    if (values[x]) {
        updateFenwick(x, -1);
    } else {
        updateFenwick(x, 1);
    }
    values[x] = 1 - values[x];  // 翻轉節點值 (0->1 或 1->0)
}

// 查詢指定區間的和
int queryRange(int l, int r) {
    return queryFenwick(r) - queryFenwick(l - 1);
}

int main() {
    int n, m, u, v, t;
    char command[3];

    // 讀取節點數
    scanf("%d", &n);
    initialize(n);  // 初始化陣列和 Fenwick Tree

    // 建立樹的鄰接表
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, i);
    }

    // 使用 DFS 標記節點的時間戳
    DFS(1);

    // 初始化每個節點的初始權值為 1
    initializeValues(n);

    // 讀取指令數量
    scanf("%d", &m);
    while (m--) {
        scanf("%s%d", command, &t);
        if (command[0] == 'Q') {  // 查詢指令
            printf("%d\n", queryRange(nodeRange[t].l, nodeRange[t].r));
        } else {  // 修改指令
            toggleValue(nodeRange[t].r);  // 翻轉權值
        }
    }

    return 0;
}

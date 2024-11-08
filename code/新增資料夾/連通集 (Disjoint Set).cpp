// Disjoint Set 連通集 - 加權合併與路徑壓縮
int parent[maxn];
fill(parent, parent + maxn, -1);  // 初始化 parent 陣列，表示每個節點是獨立的

void weighted_union2(int i, int j) {
    int temp = parent[i] + parent[j];
    if (parent[i] > parent[j]) {
        parent[i] = j;  // j為新根
        parent[j] = temp;
    } else {
        parent[j] = i;  // i為新根
        parent[i] = temp;
    }
}

int find2(int i) {
    int root, trail, lead;
    for (root = i; parent[root] >= 0; root = parent[root]);  // 找根
    for (trail = i; trail != root; trail = lead) {           // 路徑壓縮
        lead = parent[trail];
        parent[trail] = root;
    }
    return root;
}

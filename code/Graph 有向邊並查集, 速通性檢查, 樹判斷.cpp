#include <cstdio>
#include <memory>

const int MAX_SIZE = 105;
int parent[MAX_SIZE];     // 每個點的根節點
bool flag[MAX_SIZE];      // 標記每個點是否被取用

void make_set() {         // 初始化
    for (int x = 1; x < MAX_SIZE; x++) {
        parent[x] = x;
        flag[x] = false;
    }
}

int find_set(int x) {     // 尋找根節點，帶路徑壓縮
    if (x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_set(int x, int y) { // 合併兩個節點的集合
    if (x < 1 || x >= MAX_SIZE || y < 1 || y >= MAX_SIZE) return; // 加入範圍檢查
    x = find_set(x);
    y = find_set(y);
    if (x != y)
        parent[y] = x;
}

bool single_root(int n) { // 檢查是否只有一個根
    int i = 1;
    while (i <= n && !flag[i]) i++;
    if (i > n) return true; // 如果範圍內沒有使用的節點
    int root = find_set(i);
    while (i <= n) {
        if (flag[i] && find_set(i) != root)
            return false;
        ++i;
    }
    return true;
}

int main() {
    int x, y;
    bool is_tree = true;
    int range = 0;
    int idx = 1;
    make_set();

    while (scanf("%d %d", &x, &y) != EOF) {
        if (x < 0 && y < 0)
            break;
        if (x == 0 && y == 0) {
            if (is_tree && single_root(range))
                printf("Case %d is a tree.\n", idx++);
            else
                printf("Case %d is not a tree.\n", idx++);

            is_tree = true;
            range = 0;
            make_set();
            continue;
        }

        if (x >= MAX_SIZE || y >= MAX_SIZE) { // 檢查 x 和 y 是否在範圍內
            is_tree = false;
            continue;
        }

        range = x > range ? x : range;
        range = y > range ? y : range;
        flag[x] = flag[y] = true;

        if (find_set(x) == find_set(y))
            is_tree = false;
        else
            union_set(x, y);
    }

    return 0;
}

//POJ1308
#include <cstdio>
#include <memory>

const int MAX_SIZE = 105;
int parent[MAX_SIZE];     // 每個點的根節點
bool flag[MAX_SIZE];      // 標記每個點是否被取用

// 初始化集合，每個節點的父節點指向自己，標記為未使用
void make_set() {
    for (int x = 1; x < MAX_SIZE; x++) {
        parent[x] = x;
        flag[x] = false;
    }
}

// 查找集合的根，並使用路徑壓縮優化查找
int find_set(int x) {
    if (x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

// 合併兩個集合（樹），若它們的根不同，將 y 的根設為 x 的根
void union_set(int x, int y) {
    if (x < 1 || x >= MAX_SIZE || y < 1 || y >= MAX_SIZE) return; // 加入範圍檢查
    x = find_set(x);
    y = find_set(y);
    if (x != y)
        parent[y] = x;
}

// 檢查所有使用的節點是否屬於同一個集合（單一根節點）
bool single_root(int n) {
    int i = 1;
    while (i <= n && !flag[i]) i++; // 找到第一個被使用的節點
    if (i > n) return true; // 如果範圍內沒有使用的節點，則為單一根

    int root = find_set(i); // 設定第一個使用的節點的根為判斷基準
    while (i <= n) {
        if (flag[i] && find_set(i) != root) // 檢查是否所有使用的節點共享同一根
            return false;
        ++i;
    }
    return true;
}

// 判斷輸入是否構成樹的主函式
void process_input() {
    int x, y;
    bool is_tree = true;
    int range = 0;
    int case_num = 1;

    make_set();

    while (scanf("%d %d", &x, &y) != EOF) {
        if (x < 0 && y < 0)
            break;
        
        if (x == 0 && y == 0) {
            if (is_tree && single_root(range)) // 檢查結束條件
                printf("Case %d is a tree.\n", case_num++);
            else
                printf("Case %d is not a tree.\n", case_num++);
            
            is_tree = true;      // 重置為新案例
            range = 0;
            make_set();          // 重置並查集
            continue;
        }

        if (x >= MAX_SIZE || y >= MAX_SIZE) { // 檢查範圍
            is_tree = false;
            continue;
        }

        range = (x > range) ? x : range;
        range = (y > range) ? y : range;
        flag[x] = flag[y] = true;

        if (find_set(x) == find_set(y)) // 若 x 和 y 在同一集合中則形成循環，不構成樹
            is_tree = false;
        else
            union_set(x, y); // 否則合併 x 和 y
    }
}

int main() {
    process_input(); // 呼叫主函式處理輸入
    return 0;
}

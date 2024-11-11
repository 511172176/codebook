//POJ3481
#include <cstdio>
#include <cstdlib>
using namespace std;

// Treap 節點結構
struct Node {
    Node *ch[2];          // 左右子樹指標
    int v, r, info;       // v 是優先順序，info 是客戶編號，r 是節點的隨機優先級

    Node(int v, int info) : v(v), info(info) {
        r = rand();       // 隨機產生優先級
        ch[0] = ch[1] = NULL; // 初始化左右子樹為空
    }

    // 比較當前節點的優先順序和目標值 x
    int cmp(int x) {
        if (v == x) return -1;     // 若相等，返回 -1 表示找到目標
        return x < v ? 0 : 1;      // 小於當前值返回 0（左子樹），大於返回 1（右子樹）
    }
};

// Treap 左右旋轉
void rotate(Node *&o, int d) {
    Node *k = o->ch[d^1];          // 獲取旋轉後的新根
    o->ch[d^1] = k->ch[d];         // 更新 o 的子樹指標
    k->ch[d] = o;                  // 完成旋轉
    o = k;                         // 更新根節點
}

// Treap 插入節點
void insert(Node *&o, int v, int info) {
    if (o == NULL) {
        o = new Node(v, info);     // 若節點為空，創建新節點
    } else {
        int d = v < o->v ? 0 : 1;  // 若 v 小於當前節點值，放左子樹，否則右子樹
        insert(o->ch[d], v, info); // 遞迴插入左或右子樹
        if (o->ch[d]->r > o->r)    // 若新節點的優先級高於根節點
            rotate(o, d^1);        // 進行旋轉
    }
}

// Treap 刪除節點
void remove(Node *&o, int v) {
    if (!o) return;
    int d = o->cmp(v);
    if (d == -1) {                 // 若找到節點
        Node *u = o;
        if (o->ch[0] && o->ch[1]) { // 若節點有兩個子樹
            int d2 = o->ch[0]->r < o->ch[1]->r ? 1 : 0;
            rotate(o, d2);         // 進行旋轉，維持 Treap 性質
            remove(o->ch[d2], v);  // 繼續刪除節點
        } else {                   // 若只有一個子樹，將子樹提到當前位置
            o = o->ch[0] ? o->ch[0] : o->ch[1];
            delete u;              // 刪除節點
        }
    } else {
        remove(o->ch[d], v);       // 遞迴刪除左或右子樹
    }
}

// 查找 Treap 中優先順序最大的節點
int find_max(Node *o) {
    if (!o) return -1;
    while (o->ch[1] != NULL) o = o->ch[1]; // 移動到最右子節點
    printf("%d\n", o->info);               // 輸出最大優先順序的節點 info
    return o->v;
}

// 查找 Treap 中優先順序最小的節點
int find_min(Node *o) {
    if (!o) return -1;
    while (o->ch[0] != NULL) o = o->ch[0]; // 移動到最左子節點
    printf("%d\n", o->info);               // 輸出最小優先順序的節點 info
    return o->v;
}

// 處理用戶命令
void processCommands() {
    int op;
    Node *root = NULL;

    while (scanf("%d", &op) == 1 && op) {
        if (op == 1) {             // 插入新客戶
            int v, info;
            scanf("%d%d", &info, &v);
            insert(root, v, info);
        } else if (op == 2) {      // 查找最大優先順序的客戶
            if (root == NULL) {
                printf("0\n");
                continue;
            }
            int v = find_max(root);
            if (v != -1) remove(root, v);
        } else if (op == 3) {      // 查找最小優先順序的客戶
            if (root == NULL) {
                printf("0\n");
                continue;
            }
            int v = find_min(root);
            if (v != -1) remove(root, v);
        }
    }
}

int main() {
    processCommands();
    return 0;
}

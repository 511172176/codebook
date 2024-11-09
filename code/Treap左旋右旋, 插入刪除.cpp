#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node {
    Node *ch[2];         // 左右指標
    int v, r, info;      // v 是客戶優先順序，info 是客戶的編號，r 由 rand() 產生，作為節點的優先順序

    Node(int v, int info) : v(v), info(info) {
        r = rand();              // 隨機產生節點優先順序
        ch[0] = ch[1] = NULL;   // 左右指標為空
    }

    int cmp(int x) {     // 客戶優先順序 v 與 x 比較大小
        if (v == x) return -1;
        return x < v ? 0 : 1;
    }
};

void rotate(Node *&o, int d) {   // 節點 o 旋轉，方向 d = 0 左旋，1 右旋
    Node *k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o = k;
}

void insert(Node *&o, int v, int info) { // 插入一個節點 info，優先順序為 v
    if (o == NULL) {
        o = new Node(v, info); // 若找到插入位置，則客戶作為節點插入
    }
    else {
        // **Corrected Insertion Direction**: Place higher 'v' to the right
        int d = v < o->v ? 0 : 1;
        insert(o->ch[d], v, info);
        if (o->ch[d]->r > o->r) rotate(o, d^1); // 若方向 d 的子樹優先順序較小，則進行旋轉
    }
}

void remove(Node *&o, int v) { // 在 o 為根的樹狀堆棧中，刪除優先順序 v 的節點
    if (!o) return;
    int d = o->cmp(v);
    if (d == -1) { // 如果找到該節點
        Node *u = o;
        if (o->ch[0] && o->ch[1]) { // 若 o 有左右子樹，則計算被刪除節點的方向
            int d2 = o->ch[0]->r < o->ch[1]->r ? 1 : 0;
            rotate(o, d2);
            remove(o->ch[d2], v);
        } else { // 若 o 節點僅有一個子樹，則將其子樹取代 o
            o = o->ch[0] ? o->ch[0] : o->ch[1];
            delete u;
        }
    } else {
        remove(o->ch[d], v); // 若 o 節點為葉節點，直接將其刪除
    }
}

int find_max(Node *o) { // 在 o 為根的樹狀堆棧中尋找最大優先順序
    if (!o) return -1; // Handle empty treap
    while (o->ch[1] != NULL) o = o->ch[1];
    printf("%d\n", o->info);
    return o->v;
}

int find_min(Node *o) { // 在 o 為根的樹狀堆棧中尋找最小優先順序
    if (!o) return -1; // Handle empty treap
    while (o->ch[0] != NULL) o = o->ch[0];
    printf("%d\n", o->info);
    return o->v;
}

int main() {
    int op;
    Node *root = NULL;
    while (scanf("%d", &op) == 1 && op) {
        if (op == 1) { // 若輸入為新增客戶
            int v, info;
            scanf("%d%d", &info, &v);
            insert(root, v, info);
        } else if (op == 2) { // 若輸入為最大優先順序
            if (root == NULL) {
                printf("0\n");
                continue;
            }
            int v = find_max(root);
            if (v != -1) remove(root, v);
        } else if (op == 3) { // 若輸入為最小優先順序
            if (root == NULL) {
                printf("0\n");
                continue;
            }
            int v = find_min(root);
            if (v != -1) remove(root, v);
        }
    }
    return 0;
}

/*
Sample Input:
2
1 20 14
1 30 3
2
1 10 99
3
2
2
0

Expected Output:
0
20
30
10
0
*/

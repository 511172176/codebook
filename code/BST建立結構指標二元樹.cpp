#include <stdio.h>

typedef struct binTreeNode {   // 定義二元搜尋樹的結構
    int data;
    struct binTreeNode *lchild, *rchild;
} *BT;

void add(BT &T, int val) {     // 將順序值 val 插入二元搜尋樹
    if (T == NULL) {           // 若 T 為空，則找到插入位置
        T = new binTreeNode();  // 申請記憶體，建構儲存 val 的葉節點
        T->data = val;
        T->lchild = T->rchild = NULL;
    } else if (T->data > val) {  // 若 val 小於根節點值，則沿左子樹方向尋找插入點
        add(T->lchild, val);
    } else {                    // 若 val 不小於根節點值，則沿右子樹方向尋找插入位置
        add(T->rchild, val);
    }
}

void preOrder(BT T, bool flag) {  // 前序輸出樹的順序，參數 flag 為首節點標誌
    if (T == NULL)
        return;
    else {
        if (!flag)                // 若節點非首節點，則尾隨空格
            printf(" ");
        printf("%d", T->data);    // 輸出 T 的順序值
        preOrder(T->lchild, 0);   // 分別遞迴左子樹和右子樹
        preOrder(T->rchild, 0);
    }
}

int main() {
    BT T;
    int n, v;
    while (~scanf("%d", &n)) {      // 二元搜尋樹的根節點數量
        T = NULL;                   // 初始化二元搜尋樹
        for (int i = 0; i < n; i++) {
            scanf("%d", &v);        // 輸入一個個順序值
            add(T, v);              // 插入二元搜尋樹
        }
        preOrder(T, 1);             // 按照前序搜尋的順序輸出樹的順序
        printf("\n");
    }
    return 0;
}

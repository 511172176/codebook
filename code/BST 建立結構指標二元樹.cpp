//HDOJ3999
#include <stdio.h>

typedef struct binTreeNode {   // 定義二元搜尋樹的節點結構
    int data;
    struct binTreeNode *lchild, *rchild;
} *BT;

// 向二元搜尋樹中插入新值
void add(BT &T, int val) {
    if (T == NULL) {           // 若當前節點為空，則找到插入位置
        T = new binTreeNode(); // 建立新節點，並賦予初始值
        T->data = val;
        T->lchild = T->rchild = NULL; // 新節點沒有子節點
    } else if (T->data > val) { // 若值小於當前節點，則插入左子樹
        add(T->lchild, val);
    } else {                   // 若值不小於當前節點，則插入右子樹
        add(T->rchild, val);
    }
}

// 前序遍歷輸出二元搜尋樹
void preOrder(BT T, bool flag) {
    if (T == NULL)
        return;

    if (!flag)                 // 若非首節點，則在輸出前添加空格
        printf(" ");
    
    printf("%d", T->data);     // 輸出當前節點的值
    
    preOrder(T->lchild, false); // 遞迴處理左子樹，flag 設為 false
    preOrder(T->rchild, false); // 遞迴處理右子樹，flag 設為 false
}

// 建立二元搜尋樹並進行前序遍歷輸出
void buildAndPrintBST() {
    BT T = NULL;               // 初始化根節點
    int n, v;
    if (scanf("%d", &n) != 1) return; // 讀取二元搜尋樹的節點數

    for (int i = 0; i < n; i++) {
        scanf("%d", &v);       // 讀取每個節點值
        add(T, v);             // 插入二元搜尋樹
    }

    preOrder(T, true);         // 按前序順序輸出二元搜尋樹
    printf("\n");              // 輸出後換行
}

int main() {
    // 不斷讀取測試案例，建立並輸出二元搜尋樹
    while (!feof(stdin)) {
        buildAndPrintBST();
    }
    return 0;
}

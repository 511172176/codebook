//POJ2255
#include <stdio.h>
#include <string.h>

char preord[30], inord[30]; // 儲存前序和中序遍歷的字串

// 讀取每個測試案例的前序和中序遍歷
int read_case() {
    if (scanf("%s %s", preord, inord) != 2) return 0; // 若輸入不為 2 個字串，返回 0
    return 1; // 成功讀取返回 1
}

// 根據前序和中序遍歷來遞迴構建樹並輸出後序遍歷
void recover(int preleft, int preright, int inleft, int inright) {
    int root, leftsize, rightsize;

    // 根據前序的根節點位置，在中序中找到對應位置，確定左右子樹範圍
    for (root = inleft; root <= inright; root++) {
        if (preord[preleft] == inord[root]) break; // 找到中序中的根節點位置
    }

    leftsize = root - inleft;  // 左子樹的節點數
    rightsize = inright - root; // 右子樹的節點數

    // 遞迴處理左子樹
    if (leftsize > 0) 
        recover(preleft + 1, preleft + leftsize, inleft, root - 1);

    // 遞迴處理右子樹
    if (rightsize > 0) 
        recover(preleft + leftsize + 1, preright, root + 1, inright);

    // 後序輸出根節點
    printf("%c", inord[root]);
}

// 解決每個測試案例，計算並輸出後序遍歷
void solve_case() {
    int n = strlen(preord); // 前序字串的長度即為節點總數
    recover(0, n - 1, 0, n - 1); // 遞迴計算後序遍歷
    printf("\n"); // 每個案例後序遍歷結束換行
}

int main() {
    // 讀取每個測試案例並解決
    while (read_case()) solve_case();
    return 0;
}

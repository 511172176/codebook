#include <stdio.h>
#include <string.h>

char preord[30], inord[30];

int read_case() {
    if (scanf("%s %s", preord, inord) != 2) return 0;
    return 1;
}

void recover(int preleft, int preright, int inleft, int inright) {
    // 首先根據前序字串中的根節點判斷樹結構，計算左右子樹
    int root, leftsize, rightsize;

    for (root = inleft; root <= inright; root++) {
        if (preord[preleft] == inord[root]) break;  // 找到根的位置
    }

    leftsize = root - inleft;
    rightsize = inright - root;

    if (leftsize > 0)  // 遞迴左子樹
        recover(preleft + 1, preleft + leftsize, inleft, root - 1);

    if (rightsize > 0)  // 遞迴右子樹
        recover(preleft + leftsize + 1, preright, root + 1, inright);

    printf("%c", inord[root]);  // 輸出根節點
}

void solve_case() {
    int n = strlen(preord);
    recover(0, n - 1, 0, n - 1);
    printf("\n");
}

int main() {

    while (read_case()) solve_case();
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;              // 節點總數
int a[3010];        // 儲存後序遍歷

void solve(int l, int r) {     // l 和 r 是左子樹和右子樹的範圍

    if (l > r) return;         // 如果範圍無效則返回

    int i = l;
    while (i < r && a[i] < a[r]) i++;  // 找到分界點 i，使得左子樹的元素都小於 a[r]

    if (i < r ) solve(i, r - 1);    // 遞迴處理右子樹
    if (l < i ) solve(l, i - 1);     // 遞迴處理左子樹

    printf("%d\n",  a[r]);               // 輸出根節點
}

int main() {
    scanf("%d", &n);                   // 輸入節點總數
    for (int i = 0; i < n; ++i)        // 輸入後序遍歷
        scanf("%d", &a[i]);

    solve(0, n - 1);                   // 計算並輸出右子樹-左子樹-根的遍歷
    return 0;
}

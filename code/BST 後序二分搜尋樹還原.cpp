//URAL 1136
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;               // 節點總數
int a[3010];         // 儲存後序遍歷的節點值

// 從後序遍歷還原並輸出前序遍歷（右子樹-左子樹-根）
void solve(int l, int r) {
    // 如果範圍無效則返回，表示已無節點需要處理
    if (l > r) return;

    // 找到右子樹的起始位置，該位置的元素大於當前子樹根節點
    //（後序遍歷中的根節點是 a[r]）
    int i = l;
    while (i < r && a[i] < a[r]) i++;  // 找到左子樹與右子樹的分界點

    // 先遞迴處理右子樹（右子樹的範圍是 i 到 r-1）
    if (i < r) solve(i, r - 1);

    // 再遞迴處理左子樹（左子樹的範圍是 l 到 i-1）
    if (l < i) solve(l, i - 1);

    // 最後輸出根節點（後序遍歷的根節點）
    printf("%d\n", a[r]);
}

int main() {
    // 讀取節點總數
    scanf("%d", &n);

    // 讀取後序遍歷的節點數據
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    // 使用遞迴方法處理後序遍歷並輸出前序結果
    solve(0, n - 1);
    return 0;
}

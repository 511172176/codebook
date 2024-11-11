//HDOJ6667
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
long long a[N], b[N]; // 數據陣列，a[i] 和 b[i] 分別表示每個學生的兩種數據值

// 計算二分圖匹配的最大化最小值
long long maximizeMinMatchValue(int n) {
    long long ans1 = 0, ans2 = 0;

    // 計算 a[i] 和 b[i] 的累積和
    for (int i = 1; i <= n; i++) {
        ans1 += a[i]; // 累加所有 a[i] 的值
        ans2 += b[i]; // 累加所有 b[i] 的值
    }

    // 初始答案為兩個累積和的最小值
    long long ans = min(ans1, ans2);

    // 遍歷每個學生，計算匹配方案中的最小可能值
    for (int i = 1; i <= n; i++) {
        // 計算在選擇特定匹配方案下的最小值，並更新 ans
        ans = min(ans, ans1 - (a[i] - (ans2 - b[i])));
    }

    return ans; // 返回最大化的最小值
}

int main() {
    int T, n;
    scanf("%d", &T);  // 輸入測試案例數量
    while (T--) {
        scanf("%d", &n);  // 輸入學生數量

        // 讀取每個學生的數據 a[i] 和 b[i]
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &a[i], &b[i]);
        }

        // 計算並輸出結果
        printf("%lld\n", maximizeMinMatchValue(n));
    }
    return 0;
}
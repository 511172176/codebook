#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
long long a[N], b[N];

int main() {
    int T, n;
    scanf("%d", &T);  // 輸入測試案例數量
    while (T--) {
        scanf("%d", &n);  // 輸入學生數量

        long long ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld %lld", &a[i], &b[i]);  // 輸入每個學生的數據 a[i] 和 b[i]
            ans1 += a[i];  // 累計所有 a[i] 的和
            ans2 += b[i];  // 累計所有 b[i] 的和
        }

        long long ans = min(ans1, ans2);  // 計算初始的最小值為 ans1 和 ans2 中的較小者
        for (int i = 1; i <= n; i++) {
            ans = min(ans, ans1 - (a[i] - (ans2 - b[i])));  // 計算每種情況下的最小可能值
        }

        printf("%lld\n", ans);  // 輸出結果
    }
    return 0;
}

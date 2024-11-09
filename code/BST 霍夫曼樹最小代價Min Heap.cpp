#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 100;
typedef long long ll;
queue<ll> q1, q2;
ll a[maxn];
ll t, n;
bool Hufman(int x) {
    // 清空 q1 和 q2 佇列
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();

    int tt = 0;
    // 模擬 k 元霍夫曼樹：計算要使用的虛葉節點數
    if ((n - 1) % (x - 1) != 0) tt = (x - 1) - (n - 1) % (x - 1);

    // 將虛葉節點加入 q1
    for (int i = 1; i <= tt; i++) q1.push(0);
    for (int i = 1; i <= n; i++) q1.push(a[i]);  // 將序列元素加入 q1

    ll sum = 0;
    while (1) {
        ll tem = 0;
        for (int i = 1; i <= x; i++) {  // 每次取出 x 個元素
            if (q1.empty() && q2.empty()) break;
            if (q1.empty()) {
                tem += q2.front();
                q2.pop();
            } else if (q2.empty()) {
                tem += q1.front();
                q1.pop();
            } else if (q1.front() < q2.front()) {
                tem += q1.front();
                q1.pop();
            } else {
                tem += q2.front();
                q2.pop();
            }
        }
        sum += tem;
        if (q1.empty() && q2.empty()) break;
        q2.push(tem);
        if (sum > t) return 0;
    }
    return sum <= t;
}

int main() {
    int T;
    scanf("%d", &T);  // 測試案例數量
    while (T--) {
        scanf("%lld%lld", &n, &t);  // 輸入 n 和 t
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);  // 輸入每個序列元素
        sort(a + 1, a + 1 + n);  // 排序以便進行霍夫曼合併

        int st = 2, en = n;
        while (st < en) {  // 使用二分法找最小的 k 值
            int mid = (st + en) / 2;
            if (Hufman(mid)) en = mid;
            else st = mid + 1;
        }
        printf("%d\n", st);  // 輸出最小的 k 值
    }
    return 0;
}

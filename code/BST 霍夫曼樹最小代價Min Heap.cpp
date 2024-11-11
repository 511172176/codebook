//HDOJ5884
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 100;
typedef long long ll;
queue<ll> q1, q2;   // 定義兩個佇列，用於模擬 k 元霍夫曼樹
ll a[maxn];         // 儲存序列元素
ll t, n;            // 目標代價 t 和元素數量 n

// 清空佇列 q1 和 q2
void clearQueues() {
    while (!q1.empty()) q1.pop();
    while (!q2.empty()) q2.pop();
}

// 初始化佇列：根據虛葉節點和排序後的序列元素
void initializeQueue(int x) {
    int extraLeaves = (n - 1) % (x - 1) != 0 ? (x - 1) - (n - 1) % (x - 1) : 0;
    for (int i = 1; i <= extraLeaves; i++) q1.push(0); // 添加虛葉節點
    for (int i = 1; i <= n; i++) q1.push(a[i]);        // 添加序列元素
}

// 模擬 k 元霍夫曼樹，判斷是否在限制代價 t 內
bool huffman(int x) {
    clearQueues();           // 清空佇列
    initializeQueue(x);      // 初始化佇列

    ll totalCost = 0;        // 儲存霍夫曼合併的總代價

    // 進行霍夫曼合併
    while (true) {
        ll currentSum = 0;   // 當前合併的 x 個元素的總和

        for (int i = 1; i <= x; i++) {  // 每次取出 x 個元素進行合併
            if (q1.empty() && q2.empty()) break;

            if (q1.empty()) {
                currentSum += q2.front();
                q2.pop();
            } else if (q2.empty()) {
                currentSum += q1.front();
                q1.pop();
            } else if (q1.front() < q2.front()) {
                currentSum += q1.front();
                q1.pop();
            } else {
                currentSum += q2.front();
                q2.pop();
            }
        }

        totalCost += currentSum;        // 更新總代價
        if (q1.empty() && q2.empty()) break;

        q2.push(currentSum);            // 將合併結果加入 q2 佇列
        if (totalCost > t) return false; // 若超過目標代價，返回失敗
    }

    return totalCost <= t;              // 若總代價在限制內，返回成功
}

// 使用二分法查找最小的 k 值，確保代價不超過 t
int findMinK() {
    int start = 2, end = n;
    while (start < end) {
        int mid = (start + end) / 2;
        if (huffman(mid)) end = mid;
        else start = mid + 1;
    }
    return start;  // 返回找到的最小 k 值
}

// 主函式，處理多組測試案例
void processCases() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &t);              // 讀取 n 和 t
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]); // 讀取序列元素
        sort(a + 1, a + 1 + n);                 // 將序列排序
        printf("%d\n", findMinK());             // 輸出最小 k 值
    }
}

int main() {
    processCases();
    return 0;
}
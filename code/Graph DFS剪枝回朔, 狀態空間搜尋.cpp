#include <iostream>
#include <algorithm>
using namespace std;

int sticks[65]; // 用來存放木棍的長度
int used[65];   // 標記木棍是否被使用
int n, len, sum; // 木棍的數量，木棍的目標長度，所有木棍的總和

// 深度優先搜尋，檢查是否可以用目前的木棍切成長度為 len 的木棍
bool dfs(int i, int l, int t) {
    int j;

    // 若長度達到 len，則成功構成一根木棍
    if (l == 0) {
        t -= len;
        if (t == 0) return true;
        for (i = 0; used[i]; ++i); // 找到下一個未使用的木棍
        used[i] = 1; // 標記該木棍為已使用
        if (dfs(i + 1, len - sticks[i], t)) return true; // 遞迴切割
        used[i] = 0;
        return false;
    } else {
        for (int j = i; j < n; ++j) { // 從長度遞減順序尋找木棍 j 到木棍 n - 1
            if (j > 0 && sticks[j] == sticks[j - 1] && !used[j - 1]) continue; // 若長度相同且木棍 j - 1 沒有被使用則跳過
            if (!used[j] && sticks[j] <= l) { // 若木棍沒有被使用且長度小於等於當前長度
                used[j] = 1;
                if (dfs(j + 1, l - sticks[j], t)) return true; // 遞迴嘗試
                used[j] = 0;
                if (sticks[j] == l) break; // 若木棍無法完成切割則跳過
            }
        }
        return false;
    }
}

// 木棍長度的比較函數
bool cmp(const int a, const int b) {
    return a > b;
}

int main() {
    while (cin >> n && n) { // 讀取木棍數量，直至輸入 0 為止
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i];
            sum += sticks[i]; // 計算木棍總長度
            used[i] = 0;      // 初始化使用標記
        }
        sort(sticks, sticks + n, cmp); // 按木棍長度降序排列
        bool flag = false;
        for (len = sticks[0]; len <= sum / 2; ++len) { // 在 [sticks[0]..sum/2] 區間搜尋
            if (sum % len == 0) { // 若總長度能被 len 整除
                if (dfs(0, len, sum)) { // 若長度為 len 的木棍能夠切成 n 根木棍，則標記成功
                    flag = true;
                    cout << len << endl; // 輸出木棍的最小可能長度並結束計算
                    break;
                }
            }
        }
        if (!flag) cout << sum << endl; // 若找不到符合條件的木棍長度，則輸出木棍的總長度
    }
    return 0;
}

//POJ1011
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int sticks[65]; // 儲存木棍的長度
int used[65];   // 標記木棍是否被使用
int n, len, sum; // 木棍數量、目標長度、所有木棍的總長度

// 初始化木棍數據和標記
void initialize() {
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
        sum += sticks[i]; // 計算木棍總長度
        used[i] = 0;      // 初始化使用標記
    }
    sort(sticks, sticks + n, greater<int>()); // 按木棍長度降序排列
}

// DFS 搜尋木棍的切割可能性
bool dfs(int index, int remainingLength, int remainingSum) {
    // 若已組成一根長度為 len 的木棍
    if (remainingLength == 0) {
        remainingSum -= len; // 減去一根已組成木棍的長度
        if (remainingSum == 0) return true; // 若沒有剩餘長度則成功

        // 找到下一個未使用的木棍，並嘗試組成下一根木棍
        int i = 0;
        while (used[i]) ++i;
        used[i] = 1; // 標記該木棍已使用
        if (dfs(i + 1, len - sticks[i], remainingSum)) return true;
        used[i] = 0;
        return false;
    }

    // 嘗試使用剩餘木棍組成當前目標長度
    for (int j = index; j < n; ++j) {
        // 當前木棍已被使用，
        //或與前一木棍相同且前一木棍未被使用則跳過
        if (used[j] || (j > 0 && sticks[j] == sticks[j - 1] && !used[j - 1])) continue;

        // 如果木棍長度不超過當前剩餘長度，嘗試將其使用
        if (sticks[j] <= remainingLength) {
            used[j] = 1;
            if (dfs(j + 1, remainingLength - sticks[j], remainingSum)) return true;
            used[j] = 0;

            // 如果無法完成當前木棍的組合，則結束該分支
            if (sticks[j] == remainingLength) break;
        }
    }
    return false;
}

// 找到最小的木棍長度，使得所有木棍可以被完全拼接成該長度的木棍
int findMinimumStickLength() {
    for (len = sticks[0]; len <= sum / 2; ++len) { // 在 [最大木棍長度..sum/2] 區間搜尋
        if (sum % len == 0) { // 若總長度能被 len 整除
            if (dfs(0, len, sum)) return len; // 若可以組成目標長度，返回此長度
        }
    }
    return sum; // 若無法組成，返回總長度
}

int main() {
    while (cin >> n && n) { // 讀取木棍數量，直到輸入 0 為止
        initialize();       // 初始化木棍數據
        cout << findMinimumStickLength() << endl; // 找到並輸出最小的木棍可能長度
    }
    return 0;
}

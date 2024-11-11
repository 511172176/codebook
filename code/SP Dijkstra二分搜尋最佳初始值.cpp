//UVA1027
#include <bits/stdc++.h>
using namespace std;

// 將字母字符轉換成索引
int turn(char x) {
    if (x >= 'A' && x <= 'Z') return x - 'A' + 1;    // 'A'-'Z' -> 1-26
    if (x >= 'a' && x <= 'z') return x - 'a' + 27;   // 'a'-'z' -> 27-52
    return -1; // 無效字符
}

// 檢查從起點到終點的貨物量，並計算經過給定的貨物量後能到達的最大貨物量
int check(int from, int to, int o, bool go[][55]) {
    int g[55];
    memset(g, 0, sizeof(g));          // 初始化每個節點的貨物量為 0
    bool flag[55];
    memset(flag, false, sizeof(flag)); // 初始化訪問標記為 false
    g[from] = o;                       // 設定起點的初始貨物量

    while (true) {
        int w = 0, next = -1;
        // 找到貨物量最大的未標記節點
        for (int i = 1; i <= 52; i++) {
            if (!flag[i] && g[i] > w) {
                next = i;
                w = g[i];
            }
        }

        if (next == -1) break; // 無節點可以處理，退出
        flag[next] = true;     // 標記當前節點為已處理

        // 更新相鄰節點的貨物量
        for (int i = 1; i <= 52; i++) {
            if (go[next][i]) {
                int reduction;
                if (i < 27) {
                    reduction = (w + 19) / 20; // 對應於 ceil(w / 20)
                } else {
                    reduction = 1;
                }
                int tmp = w - reduction;
                if (tmp > g[i]) {
                    g[i] = tmp; // 更新節點貨物量
                }
            }
        }
    }

    return g[to]; // 返回到達目標節點的貨物量
}

// 使用二分搜尋法找到最小的初始貨物量，使得起始貨物量從 from 到 to 的最小貨物量達到 Tot
int findMinimalStartingCargo(int from, int to, int Tot, bool go[][55]) {
    int l = 1, r = (1 << 20); // 搜尋範圍設置為 1 到 1048576

    while (l < r) {
        int mid = (l + r - 1) / 2; // 計算中間值
        int cargo = check(from, to, mid, go); // 對應貨物量進行檢查
        if (cargo >= Tot) {
            r = mid; // 若符合要求，嘗試更小的初始貨物量
        } else {
            l = mid + 1; // 不符合要求，增加初始貨物量
        }
    }

    // 驗證結果：確認二分搜尋找到的貨物量能滿足要求
    if (check(from, to, l, go) >= Tot) {
        return l; // 找到最小貨物量
    } else {
        return -1; // 如果無法滿足，返回 -1 表示不可能
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // 快速輸入輸出

    int T; // 連接數
    int tot = 0; // 測試案例計數

    while (cin >> T) {
        if (T == -1) break; // 結束條件

        // 初始化鄰接矩陣
        bool go[55][55];
        memset(go, false, sizeof(go));

        // 讀取 T 條連接
        for (int i = 0; i < T; i++) {
            char x, y;
            cin >> x >> y;
            int a = turn(x);
            int b = turn(y);
            if (a == -1 || b == -1) continue; // 無效字符，跳過該連接
            go[a][b] = go[b][a] = true; // 雙向連接
        }

        // 讀取 Tot（需求的最小貨物量）
        int Tot;
        cin >> Tot;

        // 讀取起點和終點字符
        char fromChar, toChar;
        cin >> fromChar >> toChar;
        int from = turn(fromChar);
        int to = turn(toChar);

        if (from == -1 || to == -1) {
            tot++;
            cout << "Case " << tot << ": Impossible\n";
            continue;
        }

        // 使用二分搜尋法計算最小初始貨物量
        int result = findMinimalStartingCargo(from, to, Tot, go);
        tot++;
        if (result != -1) {
            cout << "Case " << tot << ": " << result << "\n";
        } else {
            cout << "Case " << tot << ": Impossible\n";
        }
    }

    return 0;
}